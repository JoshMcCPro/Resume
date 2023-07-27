package UI;

import CookieMakers.Farm;
import CookieMakers.Grandma;
import CookieMakers.Mine;
import UI.Panes.*;
import CookieMakers.Cursor;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.CheckBox;
import javafx.scene.image.Image;
import javafx.scene.layout.*;
import javafx.stage.Stage;
import javafx.util.Duration;

public class UserInterface {

    // Initializing Height and Width of user interface
    private static final int Height = 700;
    private static final int Width = 800;

    // Declaring
    private BorderPane mainPane;
    private Stage mainStage;
    private Scene mainScene;

    // Declaring Panes
    private ckNbrPane ckNbrPane = new ckNbrPane();
    private VBSidePane vbSidePane = new VBSidePane();
    private TxBuyUpgradePane txBuyUpgradePane = new TxBuyUpgradePane();
    private BuyUpgradePane buyUpgradePane = new BuyUpgradePane();
    private TxGoalPane txGoalPane = new TxGoalPane();
    private GoalPane goalPane = new GoalPane();

    // Gets button pressed and released images
    private final String BUTTON_FREE_STYLE = "-fx-background-color: transparent; -fx-background-image: url('file:src/UI/resources/buttonLong_brown.png');";
    private final String BUTTON_PRESSED_STYLE = "-fx-background-color: transparent; -fx-background-image: url('file:src/UI/resources/buttonLong_brown_pressed.png');";

    // Initializing Cookie Makers
    private Cursor cursor = new Cursor(1,10);
    private Grandma grandma = new Grandma(25,20,10);
    private Farm farm = new Farm(50,30,20);
    private Mine mine = new Mine(75,40,30);

    // Initializes
    private boolean grandmaBought = false;
    private boolean farmBought = false;
    private boolean mineBought = false;

    // Declares CheckBoxes/Goals
    private CheckBox FirstGoal = new CheckBox();
    private CheckBox SecondGoal = new CheckBox();
    private CheckBox ThirdGoal = new CheckBox();
    private CheckBox FourthGoal = new CheckBox();

    // Sets up the user interface
    public UserInterface() {
        mainPane = new BorderPane();
        mainPane.setPadding(new Insets(10,10,10,10));
        mainScene = new Scene(mainPane, Width, Height);
        mainStage = new Stage();
        mainStage.setTitle("Cookie Clicker");
        mainStage.setScene(mainScene);

        createBackground();
        createCookieClicker();
        createNbrOfCookies();
        createTxBuyUpPane();
        createBuyUpgradePane();
        createTxGoalPane();
        createGoalPane();
        createSidePane();
    }

    //  Gets the main stage
    public Stage getMainStage() {
        return mainStage;
    }

    // Creates the background of the user interface
    private void createBackground() {
        Image backgroundImage = new Image("file:src/UI/resources/Background.jpg", 1024, 1024, false, true);
        BackgroundImage background = new BackgroundImage(backgroundImage, BackgroundRepeat.REPEAT,
                BackgroundRepeat.REPEAT, BackgroundPosition.DEFAULT, null);
        mainPane.setBackground(new Background(background));
    }

    // Creates the cookie the user clicks
    private void createCookieClicker() {
        btCookieClicker cookieClicker = new btCookieClicker();
        cookieClicker.setOnMousePressed(e-> {
            cookieClicker.setCookiePressed();
            ckNbrPane.NbrOfCookies = Integer.parseInt(ckNbrPane.tfNbrOfCookies.getText()) + cursor.getCookieAmountPro();
            ckNbrPane.tfNbrOfCookies.setText(ckNbrPane.NbrOfCookies + "");

        });

        cookieClicker.setOnMouseReleased(e-> {
            cookieClicker.setCookieReleased();
        });

        mainPane.setCenter(cookieClicker);
    }

    // Creates what displays the number of cookies you have
    public void createNbrOfCookies() {
        mainPane.setTop(ckNbrPane);
    }

    // Creates and displays the Buy/Upgrade text
    public void createTxBuyUpPane() {
        vbSidePane.getChildren().add(txBuyUpgradePane);
    }

    // Creates the Buy/Upgrade pane where all the buttons are located
    public void createBuyUpgradePane() {
        createCursorButton();
        createGrandmaButton();
        createFarmButton();
        createMineButton();
        vbSidePane.getChildren().add(buyUpgradePane);
    }

    // Creates the Cursor Button
    public void createCursorButton() {
        ButtonPane btCursor = new ButtonPane("Upgrade Cursor",cursor.getCost(), cursor.getCookieAmountPro());

        btCursor.setOnMousePressed(e-> {
            btCursor.setStyle(BUTTON_PRESSED_STYLE);
            btCursor.setPrefHeight(45);
            btCursor.setTranslateY(btCursor.getTranslateY() + 4);

            if (ckNbrPane.NbrOfCookies >= cursor.getCost()) {

                ckNbrPane.NbrOfCookies = ckNbrPane.NbrOfCookies - cursor.getCost();
                ckNbrPane.tfNbrOfCookies.setText(ckNbrPane.NbrOfCookies + "");

                cursor.setCost(cursor.UpCost(15));
                btCursor.txCost.setText("Cost: " + cursor.getCost());

                cursor.setCookieAmountPro(cursor.UpCookieAmountPro(2));
                btCursor.txProduction.setText("+" + cursor.getCookieAmountPro());
            }
        });

        btCursor.setOnMouseReleased(e-> {
            btCursor.setStyle(BUTTON_FREE_STYLE);
            btCursor.setPrefHeight(49);
            btCursor.setTranslateY(btCursor.getTranslateY() - 4);
        });

        buyUpgradePane.add(btCursor,0,0);
    }

    // Creates the Grandma Button
    public void createGrandmaButton() {
        ButtonPane btGrandma = new ButtonPane("Buy Grandma",grandma.getCost(),grandma.getTime(),grandma.getCookieAmountPro());

        // Subtracts time until time hits 0 then it adds cookies to the total
        EventHandler<ActionEvent> eventHandler = new EventHandler<ActionEvent>() {

            int time = grandma.getTime();

            @Override
            public void handle(ActionEvent actionEvent) {

                if (time != 0) {
                    time--;
                    btGrandma.txTime.setText("Time: " + time);
                }

                if (time == 0) {
                    ckNbrPane.NbrOfCookies = Integer.parseInt(ckNbrPane.tfNbrOfCookies.getText()) + grandma.getCookieAmountPro();
                    ckNbrPane.tfNbrOfCookies.setText(ckNbrPane.NbrOfCookies + "");
                    time = grandma.getTime();
                    btGrandma.txTime.setText("Time: " + time);
                }
            }
        };

        // Initializing
        Timeline animation = new Timeline(new KeyFrame(Duration.seconds(1),eventHandler));

        btGrandma.setOnMousePressed(e-> {
            btGrandma.setStyle(BUTTON_PRESSED_STYLE);
            btGrandma.setPrefHeight(45);
            btGrandma.setTranslateY(btGrandma.getTranslateY() + 4);

            // Checks if user has enough cookies to upgrade
            if (ckNbrPane.NbrOfCookies >= grandma.getCost()) {

                // It calculates cost and amount of cookies
                btGrandma.text.setText("Upgrade Grandma");
                ckNbrPane.NbrOfCookies = ckNbrPane.NbrOfCookies - grandma.getCost();
                ckNbrPane.tfNbrOfCookies.setText(ckNbrPane.NbrOfCookies + "");
                grandma.setCost(grandma.UpCost(20));
                btGrandma.txCost.setText("Cost: " + grandma.getCost());

                // When bought for the first time it wont upgrade
                if(grandmaBought == true) {
                    grandma.setCookieAmountPro(grandma.UpCookieAmountPro(10));
                    btGrandma.txProduction.setText("+" + grandma.getCookieAmountPro());
                } else {
                    grandmaBought = true;
                }

                // Makes the countdown time start
                animation.setCycleCount(animation.INDEFINITE);
                animation.play();

            }
        });

        btGrandma.setOnMouseReleased(e-> {
            btGrandma.setStyle(BUTTON_FREE_STYLE);
            btGrandma.setPrefHeight(49);
            btGrandma.setTranslateY(btGrandma.getTranslateY() - 4);
        });

        buyUpgradePane.add(btGrandma,0,1);
    }

    // Creates the Farm Button
    public void createFarmButton() {
        ButtonPane btFarm = new ButtonPane("Buy Farm",farm.getCost(),farm.getTime(),farm.getCookieAmountPro());

        // Subtracts time until time hits 0 then it adds cookies to the total
        EventHandler<ActionEvent> eventHandler = new EventHandler<ActionEvent>() {

            int time = farm.getTime();

            @Override
            public void handle(ActionEvent actionEvent) {

                if (time != 0) {
                    time--;
                    btFarm.txTime.setText("Time: " + time);
                }

                if (time == 0) {
                    ckNbrPane.NbrOfCookies = Integer.parseInt(ckNbrPane.tfNbrOfCookies.getText()) + farm.getCookieAmountPro();
                    ckNbrPane.tfNbrOfCookies.setText(ckNbrPane.NbrOfCookies + "");
                    time = farm.getTime();
                    btFarm.txTime.setText("Time: " + time);
                }
            }
        };

        // Initializing
        Timeline animation = new Timeline(new KeyFrame(Duration.seconds(1),eventHandler));

        btFarm.setOnMousePressed(e-> {
            btFarm.setStyle(BUTTON_PRESSED_STYLE);
            btFarm.setPrefHeight(45);
            btFarm.setTranslateY(btFarm.getTranslateY() + 4);

            // Checks if user has enough cookies to upgrade
            if (ckNbrPane.NbrOfCookies >= farm.getCost()) {

                // It calculates cost and amount of cookies
                btFarm.text.setText("Upgrade Farm");
                ckNbrPane.NbrOfCookies = ckNbrPane.NbrOfCookies - farm.getCost();
                ckNbrPane.tfNbrOfCookies.setText(ckNbrPane.NbrOfCookies + "");
                farm.setCost(farm.UpCost(30));
                btFarm.txCost.setText("Cost: " + farm.getCost());

                // When bought for the first time it wont upgrade
                if(farmBought == true) {
                    farm.setCookieAmountPro(farm.UpCookieAmountPro(25));
                    btFarm.txProduction.setText("+" + farm.getCookieAmountPro());
                } else {
                    farmBought = true;
                }

                // Makes the countdown time start
                animation.setCycleCount(animation.INDEFINITE);
                animation.play();

            }
        });

        btFarm.setOnMouseReleased(e-> {
            btFarm.setStyle(BUTTON_FREE_STYLE);
            btFarm.setPrefHeight(49);
            btFarm.setTranslateY(btFarm.getTranslateY() - 4);
        });

        buyUpgradePane.add(btFarm,0,2);
    }

    // Creates the Mine Button
    public void createMineButton() {
        ButtonPane btMine = new ButtonPane("Buy Mine",mine.getCost(),mine.getTime(),mine.getCookieAmountPro());

        // Subtracts time until time hits 0 then it adds cookies to the total
        EventHandler<ActionEvent> eventHandler = new EventHandler<ActionEvent>() {

            int time = mine.getTime();

            @Override
            public void handle(ActionEvent actionEvent) {

                if (time != 0) {
                    time--;
                    btMine.txTime.setText("Time: " + time);
                }

                if (time == 0) {
                    ckNbrPane.NbrOfCookies = Integer.parseInt(ckNbrPane.tfNbrOfCookies.getText()) + mine.getCookieAmountPro();
                    ckNbrPane.tfNbrOfCookies.setText(ckNbrPane.NbrOfCookies + "");
                    time = mine.getTime();
                    btMine.txTime.setText("Time: " + time);
                }
            }
        };

        // Initializing
        Timeline animation = new Timeline(new KeyFrame(Duration.seconds(1),eventHandler));

        btMine.setOnMousePressed(e-> {
            btMine.setStyle(BUTTON_PRESSED_STYLE);
            btMine.setPrefHeight(45);
            btMine.setTranslateY(btMine.getTranslateY() + 4);

            // Checks if user has enough cookies to upgrade
            if (ckNbrPane.NbrOfCookies >= mine.getCost()) {

                // It calculates cost and amount of cookies
                btMine.text.setText("Upgrade Mine");
                ckNbrPane.NbrOfCookies = ckNbrPane.NbrOfCookies - mine.getCost();
                ckNbrPane.tfNbrOfCookies.setText(ckNbrPane.NbrOfCookies + "");
                mine.setCost(mine.UpCost(40));
                btMine.txCost.setText("Cost: " + mine.getCost());

                // When bought for the first time it wont upgrade
                if(mineBought == true) {
                    mine.setCookieAmountPro(mine.UpCookieAmountPro(30));
                    btMine.txProduction.setText("+" + mine.getCookieAmountPro());
                } else {
                    mineBought = true;
                }

                // Makes the countdown time start
                animation.setCycleCount(animation.INDEFINITE);
                animation.play();

            }
        });

        btMine.setOnMouseReleased(e-> {
            btMine.setStyle(BUTTON_FREE_STYLE);
            btMine.setPrefHeight(49);
            btMine.setTranslateY(btMine.getTranslateY() - 4);
        });

        buyUpgradePane.add(btMine,0,3);
    }

    // Creates and displays the Goals text
    public void createTxGoalPane() {
        vbSidePane.getChildren().add(txGoalPane);
    }

    // Creates the Goal pane where all the goals are located
    public void createGoalPane() {
        createFirstGoal();
        createSecondGoal();
        createThirdGoal();
        createFourthGoal();
        createCheckGoals();
        vbSidePane.getChildren().add(goalPane);
    }

    // Creates the First Goal
    public void createFirstGoal() {
        FirstGoal.setText("100");
        FirstGoal.setOpacity(100);
        FirstGoal.setSelected(false);
        FirstGoal.setDisable(true);

        goalPane.add(FirstGoal,0,0);
    }

    // Creates the Second Goal
    public void createSecondGoal() {
        SecondGoal.setText("1000");
        SecondGoal.setOpacity(100);
        SecondGoal.setSelected(false);
        SecondGoal.setDisable(true);

        goalPane.add(SecondGoal,0,1);
    }

    // Creates the Third Goal
    public void createThirdGoal() {
        ThirdGoal.setText("10000");
        ThirdGoal.setOpacity(100);
        ThirdGoal.setSelected(false);
        ThirdGoal.setDisable(true);

        goalPane.add(ThirdGoal,0,2);
    }

    // Creates the Fourth Goal
    public void createFourthGoal() {
        FourthGoal.setText("100000");
        FourthGoal.setOpacity(100);
        FourthGoal.setSelected(false);
        FourthGoal.setDisable(true);

        goalPane.add(FourthGoal,1,0);
    }

    // Checks if the user has met the requirements for the goals
    public void createCheckGoals() {

        EventHandler<ActionEvent> eventHandler = new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent actionEvent) {
                // First Goal
                if (ckNbrPane.NbrOfCookies >= Integer.parseInt(FirstGoal.getText())) {
                    FirstGoal.setSelected(true);
                }

                // Second Goal
                if (ckNbrPane.NbrOfCookies >= Integer.parseInt(SecondGoal.getText())) {
                    SecondGoal.setSelected(true);
                }

                // Third Goal
                if (ckNbrPane.NbrOfCookies >= Integer.parseInt(ThirdGoal.getText())) {
                    ThirdGoal.setSelected(true);
                }

                // Fourth Goal
                if (ckNbrPane.NbrOfCookies >= Integer.parseInt(FourthGoal.getText())) {
                    FourthGoal.setSelected(true);
                }

            }
        };

        Timeline Check = new Timeline(new KeyFrame(Duration.millis(1),eventHandler));
        Check.setCycleCount(Check.INDEFINITE);
        Check.play();
    }

    // Crates the right side pane where the Buttons and Goals are located
    public void createSidePane() {
        mainPane.setRight(vbSidePane);
    }
}
