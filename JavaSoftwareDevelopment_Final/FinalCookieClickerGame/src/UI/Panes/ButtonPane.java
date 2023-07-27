package UI.Panes;

import javafx.geometry.Insets;
import javafx.scene.effect.DropShadow;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.Text;

public class ButtonPane extends GridPane {

    // Gets button released image
    private final String BUTTON_FREE_STYLE = "-fx-background-color: transparent; -fx-background-image: url('file:src/UI/resources/buttonLong_brown.png');";

    // initializing
    public Text text = new Text("Upgrade Cursor");
    private int cost = 10;
    public Text txCost = new Text("Cost: " + cost);
    private int time = 10;
    public Text txTime = new Text("Time: " + time);
    private int production = 10;
    public Text txProduction = new Text("+" + production);

    // initializing
    private ckNbrPane nbrPane = new ckNbrPane();

    // Sets up the Button pane
    public ButtonPane(String ButtonName, int Cost, int Production) {
        setPadding(new Insets(6,6,6,6));
        setTxCostLayout();
        text.setText(ButtonName);
        txCost.setText("Cost: " + Cost);
        txProduction.setText("+" + Production);
        setPrefWidth(190);
        setPrefHeight(49);
        setStyle(BUTTON_FREE_STYLE);
        initializeButtonListeners();
    }

    // Sets up the Button pane
    public ButtonPane(String ButtonName, int Cost, int Time, int Production) {
        setPadding(new Insets(6,6,6,6));
        setTxCostLayout();
        setTxTimeLayout();
        text.setText(ButtonName);
        txCost.setText("Cost: " + Cost);
        txTime.setText("Time: " + Time);
        txProduction.setText("+" + Production);
        setPrefWidth(190);
        setPrefHeight(49);
        setStyle(BUTTON_FREE_STYLE);
        initializeButtonListeners();
    }

    // sets the layout of the text,production,cost on the button
    private void setTxCostLayout() {

        text.setFont(Font.font("Verdana",16));
        text.setFill(Color.WHITE);
        add(text,0,0);

        txProduction.setFont(Font.font("Verdana",10));
        txProduction.setFill(Color.WHITE);
        txProduction.setTranslateX(150);
        add(txProduction,0,0);

        txCost.setFont(Font.font("Verdana",10));
        txCost.setFill(Color.WHITE);
        add(txCost,0,1);

    }

    // sets the layout of the time on the button
    private void setTxTimeLayout() {
        txTime.setFont(Font.font("Verdana",10));
        txTime.setFill(Color.WHITE);
        txTime.setTranslateX(75);
        add(txTime,0,1);
    }

    // initializes button listeners
    private void initializeButtonListeners() {

        setOnMouseEntered(e-> {
            setEffect(new DropShadow());
        });

        setOnMouseExited(e-> {
            setEffect(null);
        });
    }
}
