package test;

public class test1 {
    public static void main(String[] args) {
        System.out.println("******************");
        int i = 0;
        while(i < 7){
            int count = 0;
            int j = 0, n = 0;
            while(j < spectrum[0].length) {
                if (!spectrum[i][j]) {
                    count = 0;
                    j++;
                    continue;
                } else {

                    count++;
                    if (count == demandInSlots) {
                        for (int k = j - demandInSlots + 1; k <= j; k++) {
                            Slot s = new Slot(i,k);
                            s.modulation = modulationLevel;
                            fittedSlotList.add(s);
                        }
                        n = fittedSlotList.get(0).s;
                        //todo: per slot ----> dynamic n : CrosstalkIsAcceptablePerSlot2 static n :CrosstalkIsAcceptablePerSlot per     per link--->dynamic n : CrosstalkIsAcceptablePerLink2   static n :  CrosstalkIsAcceptablePerLink          调制 所有的串扰----> dynamic n : CrosstalkIsAcceptable2   static n :   CrosstalkIsAcceptable
                        if(cp.CrosstalkIsAcceptable2(flow, links, fittedSlotList, Modulations_mine.inBandXT[modulationLevel - 1])) {
                            //todo:shit不能将fittedSlotList加进去，要new 一个，因为fittedSlotList是个引用，指向的数据会变化的
                            block.add(new ArrayList<>(fittedSlotList));
//                            establishConnection(links, fittedSlotList, 0, flow);
//                            return true;
                        }
//                            j = fittedSlotList.get(0).s;
                        fittedSlotList.clear();
                        count = 0;
                        j = n;
                    }
                    j++;
                }
//                System.out.println(j);
            }
            //todo:计算每个符合要求的频谱块的总的 active n 选择那个最小的建立连接        只是通过----每条链路的频谱---来计算总的active n

            //todo:这里的目的是计算每个适合的频谱的ASR_SSE(ASR与SSE都是假设将频谱分配进去了之后，再来计算的)，并对他们进行排序      用到优先队列比较好吧
//            if(block.size() > 0) {
//                int max = 0;
//                //todo：用于存储对应下标的频谱块的总的active n
//                int[] index = new int[block.size()];
//                for(int k = 0; k < block.size(); ++k) {
//                    for(Slot s : block.get(k)) {
////                        index[k] += pt.getAllACtiveN(links,s);
//                        //todo:这里要用强转是因为getAllActiveN这个方法是ControlPlane实现类独有的
//                        ControlPlane temp = (ControlPlane)cp;
//                        index[k] += temp.getAllActiveN(links,s);
//                    }
//                    if(index[k] < index[max]) {
//                        max = k;
//                    }
//                }
//                establishConnection(links, block.get(max), 0, flow);
//                return true;
//            }else {
//                fittedSlotList.clear();
//                block.clear();
//            }

            //todo:存储每个可用频谱块(此可用频谱块是可能有重叠的)的npfr、asr、sse、asr_sse        asr_sse越大越好
            double[][] asr_sse = new double[block.size()][5];

            if(block.size() > 0) {
                for(int k = 0; k < block.size(); ++k) {
//                    asr_sse[k][0] = calculateNPFRAfterAllocation(block, k);
//                    asr_sse[k][1] = getFreeSlotPerCore(i, demandInSlots) * (1 - asr_sse[k][0]);

                    asr_sse[k][0] = calculateSumOfBlockAfterAllocation(block.get(k));
                    asr_sse[k][1] = getFreeSlotPerCore(i, demandInSlots) * asr_sse[k][0];

                    //todo:这里要用强转是因为getAllActiveN这个方法是ControlPlane实现类独有的
                    ControlPlane temp = (ControlPlane)cp;
                    double countXt = 0;
                    for(Slot s : block.get(k)) {
                        countXt += temp.getAllActiveN(links, s);
                    }
                    asr_sse[k][2] = countXt / (demandInSlots * xt.getAdjacentsCores(i).size());
                    asr_sse[k][3] = asr_sse[k][1] * (1 - asr_sse[k][2]);
                    asr_sse[k][4] = k;
                }

                //todo:为什么会报这个错误？？？？？Comparison method violates its general contract!       Double.compare(o1[3], o2[3]);
//                Arrays.sort(asr_sse, (a, b )-> (int) (a[3] - b[3]));
                //todo:这里应该是降序
                Arrays.sort(asr_sse, new Comparator<double[]>() {
                    @Override
                    public int compare(double[] o1, double[] o2) {
                        return Double.compare(o2[3], o1[3]);
                    }
                });

                establishConnection(links, block.get((int)asr_sse[0][4]), 0, flow);
                return true;
            }else {
                fittedSlotList.clear();
                block.clear();
            }
            i++;

        }
    }
}

