package UI.Panes;

import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.GridPane;

public class ckNbrPane extends GridPane{
    // Gets the cookie image
    private final String IMAGE_PATH = "file:src/UI/resources/Cookie.png";

    // Declaring and initializing
    public TextField tfNbrOfCookies;
    public int NbrOfCookies = 0;

    //Sets up the Cookie Number Pane
    public ckNbrPane() {
        setImage();
        createTfNbrOfCookies();
    }

    // Sets up the cookie image on the pane
    public void setImage() {
        Image imCookie = new Image(IMAGE_PATH);
        ImageView viewCookie = new ImageView(imCookie);
        viewCookie.setFitWidth(32);
        viewCookie.setFitHeight(32);
        add(viewCookie,0,0);
    }

    // Creates the text field where the number of cookies are displayed
    public void createTfNbrOfCookies() {
        tfNbrOfCookies = new TextField("0");
        tfNbrOfCookies.setPrefColumnCount(5);
        tfNbrOfCookies.setEditable(false);
        tfNbrOfCookies.setAlignment(Pos.CENTER_RIGHT);
        add(tfNbrOfCookies,1,0);
    }

}
