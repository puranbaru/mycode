public class Fraction {
    private int numerator;
    private int denominator;

    public Fraction(int n, int d) {
        if (d == 0) {
            throw new ArithmeticException();
        }
        numerator = n;
        denominator = d;
    }

    public int getNum() {
        return numerator;
    }

    public int getDenom() {
        return denominator;
    }

    public void setNum(int n) {
        numerator = n;
    }

    public void setDenom(int d) {
        if (d == 0) {
            throw new ArithmeticException();
        }
        denominator = d;
    }

    public Fraction add(Fraction a) {
        int num = numerator * a.getDenom() + a.getNum() * denominator;
        int den = denominator * a.getDenom();
        return new Fraction(num, den);
    }

    public boolean equals(Fraction a) {
        return numerator * a.getDenom() == denominator * a.getNum();
    }

    public String toString() {
        return numerator + "/" + denominator;
    }
}