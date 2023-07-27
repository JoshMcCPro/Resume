package UI.Panes;

import javafx.geometry.Insets;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;

public class BuyUpgradePane extends GridPane {

    // Sets up the pane
    public BuyUpgradePane() {
        SetupBuyUpgradePane();
    }

    // Sets up the Buy/Upgrade pane
    private void SetupBuyUpgradePane() {
        setPrefHeight(250);
        setHgap(5);
        setVgap(5);
        setPadding(new Insets(10,10,10,10));
        setBackground(new Background(new BackgroundFill(Color.BURLYWOOD,
                CornerRadii.EMPTY, Insets.EMPTY)));
        setBorder(new Border(new BorderStroke(Color.BLACK,
                BorderStrokeStyle.SOLID, CornerRadii.EMPTY, BorderWidths.DEFAULT)));
    }
}
