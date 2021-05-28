package ���ݽṹ;
/**
 * @Author: Blue
 * @Date: 2021/5/11
 * @Time: 19:30
 * @Description:
 */
public class Modulations_mine {
    /**
     * The Class Modulations.
     */
    public static final int numberOfModulations = 6;

    /**
     * TODO:���ű���������Ӧ��BPSK, QPSK, 16QAM, 64QAM
     * �е㲻�԰���������û���ԣ����modulation level �ǰ��վ�������ȡ�ģ�������������getModulationByDistance
     */
    public static final int numberOfSymbols[] = {1,2,3,4,5,6};  //��Ӧ��2�Ĵη�
    /** The Constant distance. */
//    public static final int maxDistance[] = {4000,2000,1000,500,250,125};
//    public static final int maxDistance[] = {8000,4000,2000,1000,500,250};
    public static final int maxDistance[] = {9600,4800,2400,1200,600,300};
    /**
     * SNR threshold for the correct ������Ȼ�����ֵ������������
     */
    public static final double SNR_THRESHOLD[] = {6,9,12,15,18,21};


    /**
     * о�䴮�ţ���Ӧ��BPSK, QPSK, 16QAM, 64QAM�����ֵ���԰�����������
     */
    public static final double inBandXT[] = {-22.75,-25.76,-28.77,-31.79,-34.8,-37.81};
//    public static final double inBandXT[] = {-14,-18.5,-21,-25,-27,-34};

    public static double k = 3.16 * Math.pow(10, -4);
    public static double r = 55 * Math.pow(10, -3);
    public static double bita = 4 * Math.pow(10, 6);
    public static double w = 45 * Math.pow(10, -6);

    public static double getH() {
        return (2 * (k * k) *r) / (bita * w);
    }

    public static double calculateXT_DB(int n, int distance) {
        double h = Modulations_mine.getH();
//        double h = 6.1*Math.pow(10,-12);
        distance *= 1000;
        double temp =  n * Math.pow(Math.E, -(n + 1) * h * distance * 2);
        double xt = (n - temp)/(1 + temp);

        return xt;
//        return convertToDB(xt);
    }

    public static double convertToDB(double p) {
        return 10.0f * Math.log10(p)/Math.log10(10);
//		return ( 10.0f * Math.log10(p/10.0) );
    }

    /**
     * Number of modulations.
     *
     * @return the int
     */
    public static int numberOfModulations(){
        return numberOfModulations;
    }
    /**
     * Gets the bandwidth.
     *
     * @param modulationLevel the modulation level
     * @param
     * @return the bandwidth which modulation level can transmit
     */
    public static double getBandwidth(int modulationLevel){
        return numberOfSymbols[modulationLevel] * 12.5;
    }


    /**
     * Gets the max distance.
     *
     * @param modulationLevel the modulation level
     * @return the max distance
     */
    public static int getMaxDistance(int modulationLevel){
        if (modulationLevel >= 0 && modulationLevel <= 5){
            return maxDistance[modulationLevel];
        } else {
            return maxDistance[0];
        }
    }

    /**
     * Gets the max distance.
     *
     * @param modulationLevel the modulation level
     * @return the max distance
     */
    public static double getSNRThreshold(int modulationLevel){
        if (modulationLevel >= 0 && modulationLevel <= 5){
            return SNR_THRESHOLD[modulationLevel];
        } else {
            return SNR_THRESHOLD[0];
        }
    }

    /**
     * Gets the modulation by distance.
     *
     * @param givendistance the distance
     * @return the modulation by distance
     */
    //todo:����level��С���Ӧ�����������ĵ���ˮƽӦ�ü���1
    public static int getModulationByDistance(int givendistance){
        int i = numberOfModulations-1;
        while (givendistance >= maxDistance[i] && i >= 1){
            i--;
        }
        return i;
    }

    /**
     * @param cores
     * @return worst aggregate inter core crosstalk crosstalk ����ĺ˼䴮�ţ�����о���йأ�������
     */
    public static double interCoreXT(int cores) {
        if (cores <= 7) {
            return -45;
        } else if (cores > 7 && cores <=12) {
            return -31;
        } else if (cores >12) {
            return -20;
        } else {
            return 1000;
        }
    }

}
