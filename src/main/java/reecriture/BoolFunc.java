package reecriture;

public interface BoolFunc {
    BoolFunc ONLYSECOND = (a, b) -> {
        return b && !a;
    };
    BoolFunc ONLYFIRST = (a, b) -> {
        return a && !b;
    };
    boolean apply(boolean a1, boolean a2);
}
