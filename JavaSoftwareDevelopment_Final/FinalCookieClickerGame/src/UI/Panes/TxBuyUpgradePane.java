package UI.Panes;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;

public class TxBuyUpgradePane extends HBox {

    // Sets up the text Buy/Upgrade pane
    public TxBuyUpgradePane() {
        SetupBuyUpgradeText();
    }

    // Sets up the text Buy/Upgrade pane
    private void SetupBuyUpgradeText() {
        setPadding(new Insets(10,10,10,10));
        setPrefHeight(50);
        setBackground(new Background(new BackgroundFill(Color.BROWN,
                CornerRadii.EMPTY, Insets.EMPTY)));
        setBorder(new Border(new BorderStroke(Color.BLACK,
                BorderStrokeStyle.SOLID, CornerRadii.EMPTY, BorderWidths.DEFAULT)));
        setAlignment(Pos.CENTER);
        Text text = new Text("Buy/Upgrade");
        text.setFont(Font.font("Verdana", FontWeight.BOLD, 20));
        text.setFill(Color.WHITE);
        getChildren().add(text);
    }
}
