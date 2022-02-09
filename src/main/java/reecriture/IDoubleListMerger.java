package reecriture;

import java.util.List;

public class IDoubleListMerger implements IMerger{
    private final List<Double> result;
    private final List<Integer> firstIndices;
    private final List<Integer> secondIndices;

    public IDoubleListMerger(List<Double> result, List<Integer> firstIndices, List<Integer> secondIndices) {
        this.result = result;
        this.firstIndices = firstIndices;
        this.secondIndices = secondIndices;
    }
    public List<Double> getList(){
        return this.result;
    }
    public boolean forMergedIndexes(IDoubleListMerger.IConsumer p_197855_1_) {
        int size = this.result.size();
        for(int i = 0; i <size  - 1; ++i) {
            if (!p_197855_1_.merge(this.firstIndices.get(i), this.secondIndices.get(i), i)) {
                return false;
            }
        }

        return true;
    }

}
