import thread.VillageChecker;
import thread.testVillageGen;

public class Main {
    public static void main(String[] args) {
        int TOTAL_THREADS = 1;
        System.out.println("lets go");

        for(int offset = 0; offset< TOTAL_THREADS; offset++) {
            System.out.println("test");
            Runnable myThread = new testVillageGen(offset, TOTAL_THREADS);
            new Thread(myThread).start();
        }
    }
}
