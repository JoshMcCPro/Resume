package CookieMakers;

// Creates Cursor class
public class Cursor extends CookieMaker {
    // initializing variables
    private int cookieAmountPro = 0;
    private int cost = 0;

    // Cursor method
    public Cursor() {

    }

    // Cursor method that you can input cookie production and cost
    public Cursor(int cookieAmountPro, int cost) {
        this.cookieAmountPro = cookieAmountPro;
        this.cost = cost;
    }

    // Gets cookie production amount
    @Override
    public int getCookieAmountPro() {
        return cookieAmountPro;
    }

    // Sets the new cookie production
    @Override
    public void setCookieAmountPro(int cookieAmountPro) {
        this.cookieAmountPro = cookieAmountPro;
    }

    // Gets the cost of the Cursor
    @Override
    public int getCost() {
        return cost;
    }

    // Sets the new cost of the Cursor
    @Override
    public void setCost(int cost) {
        this.cost = cost;
    }

    // Adds to the cost
    @Override
    public int UpCost(int addAmount) {
        return getCost() + addAmount;
    }

    // Adds to the cookie production
    @Override
    public int UpCookieAmountPro(int addAmount) {
        return getCookieAmountPro() + addAmount;
    }

}
