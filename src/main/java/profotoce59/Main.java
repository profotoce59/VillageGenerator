package profotoce59;

import profotoce59.thread.testVillageGen;

public class Main {
    public static void main(String[] args) {
        int TOTAL_THREADS = 1;
        System.out.println("lets go");

        for(int offset = 0; offset< TOTAL_THREADS; offset++) {
            System.out.println("test");
            Runnable myThread = new testVillageGen(offset, TOTAL_THREADS);
           //Runnable myThread = new WorldSeedThread(offset, TOTAL_THREADS, -6302174073431413815L);
            new Thread(myThread).start();
        }
    }
}
