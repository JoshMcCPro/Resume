package CookieMakers;

// Creates CookieMaker abstract class
public abstract class CookieMaker {
    // initializing variables
    private int cookieAmountPro = 0;
    private int cost = 0;
    private int time = 0;

    // CookieMaker method
    protected CookieMaker() {

    }

    // CookieMaker method that you can input cookie production and cost
    protected CookieMaker(int cookieAmountPro, int cost) {
        this.cookieAmountPro = cookieAmountPro;
        this.cost = cost;
    }

    // CookieMaker method that you can input cookie production, cost, and time
    protected CookieMaker(int cookieAmountPro, int cost, int time) {
        this.cookieAmountPro = cookieAmountPro;
        this.cost = cost;
        this.time = time;
    }

    // Gets cookie production amount
    public int getCookieAmountPro() {
        return cookieAmountPro;
    }

    // Sets the new cookie production
    public void setCookieAmountPro(int cookieAmountPro) {
        this.cookieAmountPro = cookieAmountPro;
    }

    // Gets the cost of the Cookie Maker
    public int getCost() {
        return cost;
    }

    // Sets the new cost of the Cookie Maker
    public void setCost(int cost) {
        this.cost = cost;
    }

    // Get the time
    public int getTime() {
        return time;
    }

    // Sets the new time
    public void setTime(int time) {
        this.time = time;
    }

    // Adds to the cost
    public abstract int UpCost(int addAmount);

    // Adds to the cookie production
    public abstract int UpCookieAmountPro(int addAmount);
}
