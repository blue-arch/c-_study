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
                        //todo: per slot ----> dynamic n : CrosstalkIsAcceptablePerSlot2 static n :CrosstalkIsAcceptablePerSlot per     per link--->dynamic n : CrosstalkIsAcceptablePerLink2   static n :  CrosstalkIsAcceptablePerLink          ���� ���еĴ���----> dynamic n : CrosstalkIsAcceptable2   static n :   CrosstalkIsAcceptable
                        if(cp.CrosstalkIsAcceptable2(flow, links, fittedSlotList, Modulations_mine.inBandXT[modulationLevel - 1])) {
                            //todo:shit���ܽ�fittedSlotList�ӽ�ȥ��Ҫnew һ������ΪfittedSlotList�Ǹ����ã�ָ������ݻ�仯��
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
            //todo:����ÿ������Ҫ���Ƶ�׿���ܵ� active n ѡ���Ǹ���С�Ľ�������        ֻ��ͨ��----ÿ����·��Ƶ��---�������ܵ�active n

            //todo:�����Ŀ���Ǽ���ÿ���ʺϵ�Ƶ�׵�ASR_SSE(ASR��SSE���Ǽ��轫Ƶ�׷����ȥ��֮�����������)���������ǽ�������      �õ����ȶ��бȽϺð�
//            if(block.size() > 0) {
//                int max = 0;
//                //todo�����ڴ洢��Ӧ�±��Ƶ�׿���ܵ�active n
//                int[] index = new int[block.size()];
//                for(int k = 0; k < block.size(); ++k) {
//                    for(Slot s : block.get(k)) {
////                        index[k] += pt.getAllACtiveN(links,s);
//                        //todo:����Ҫ��ǿת����ΪgetAllActiveN���������ControlPlaneʵ������е�
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

            //todo:�洢ÿ������Ƶ�׿�(�˿���Ƶ�׿��ǿ������ص���)��npfr��asr��sse��asr_sse        asr_sseԽ��Խ��
            double[][] asr_sse = new double[block.size()][5];

            if(block.size() > 0) {
                for(int k = 0; k < block.size(); ++k) {
//                    asr_sse[k][0] = calculateNPFRAfterAllocation(block, k);
//                    asr_sse[k][1] = getFreeSlotPerCore(i, demandInSlots) * (1 - asr_sse[k][0]);

                    asr_sse[k][0] = calculateSumOfBlockAfterAllocation(block.get(k));
                    asr_sse[k][1] = getFreeSlotPerCore(i, demandInSlots) * asr_sse[k][0];

                    //todo:����Ҫ��ǿת����ΪgetAllActiveN���������ControlPlaneʵ������е�
                    ControlPlane temp = (ControlPlane)cp;
                    double countXt = 0;
                    for(Slot s : block.get(k)) {
                        countXt += temp.getAllActiveN(links, s);
                    }
                    asr_sse[k][2] = countXt / (demandInSlots * xt.getAdjacentsCores(i).size());
                    asr_sse[k][3] = asr_sse[k][1] * (1 - asr_sse[k][2]);
                    asr_sse[k][4] = k;
                }

                //todo:Ϊʲô�ᱨ������󣿣�������Comparison method violates its general contract!       Double.compare(o1[3], o2[3]);
//                Arrays.sort(asr_sse, (a, b )-> (int) (a[3] - b[3]));
                //todo:����Ӧ���ǽ���
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

