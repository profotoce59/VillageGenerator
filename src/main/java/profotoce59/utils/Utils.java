package profotoce59.utils;

import com.seedfinding.mccore.util.pos.BPos;

import java.util.Iterator;
import java.util.Spliterator;
import java.util.function.Consumer;

public class Utils {

    public static Iterable<BPos> getAllInBoxMutable(BPos firstPos, BPos secondPos) {
        return getAllInBoxMutable(Math.min(firstPos.getX(), secondPos.getX()), Math.min(firstPos.getY(), secondPos.getY()), Math.min(firstPos.getZ(), secondPos.getZ()), Math.max(firstPos.getX(), secondPos.getX()), Math.max(firstPos.getY(), secondPos.getY()), Math.max(firstPos.getZ(), secondPos.getZ()));
    }

    public static Iterable<BPos> getAllInBoxMutable(int x1, int y1, int z1, int x2, int y2, int z2) {
        int i = x2 - x1 + 1;
        int j = y2 - y1 + 1;
        int k = z2 - z1 + 1;
        int l = i * j * k;
        return new Iterable<BPos>() {
            @Override
            public Iterator<BPos> iterator() {
                return new Iterator<BPos>() {
                    int totalAmount = 0;
                    @Override
                    public boolean hasNext() {
                        return totalAmount == l;
                    }

                    @Override
                    public BPos next() {
                        int i1 = this.totalAmount % i;
                        int j1 = this.totalAmount / i;
                        int k1 = j1 % j;
                        int l1 = j1 / j;
                        ++this.totalAmount;
                        return new BPos(x1 + i1, y1 + k1, z1 + l1);
                    }
                };
            }

            @Override
            public void forEach(Consumer<? super BPos> action) {
                Iterable.super.forEach(action);
            }

            @Override
            public Spliterator<BPos> spliterator() {
                return Iterable.super.spliterator();
            }
        };
    }
}
