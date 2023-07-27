package UI;

import javafx.scene.effect.DropShadow;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;

public class btCookieClicker extends ImageView {

    // Gets the image of the cookie
    private final String IMAGE_PATH = "file:src/UI/resources/Cookie.png";

    // Sets up the cookie clicker button
    public btCookieClicker() {
        setCookieImage();
        setFitWidth(256);
        setFitHeight(256);
        initializeCookieListeners();

    }

    // Sets the image of the button
    private void setCookieImage() {
        Image image = new Image(IMAGE_PATH);
        setImage(image);
    }

    // Sets up what happens when cookie is pressed
    public void setCookiePressed() {
        setFitHeight(250);
        setTranslateY(getTranslateY() + 4);
    }

    // Sets up what happens when cookie is Released
    public void setCookieReleased() {
        setFitHeight(256);
        setTranslateY(getTranslateY() - 4);
    }

    // initializes listeners
    private void initializeCookieListeners() {

        setOnMouseEntered(e-> {
            setEffect(new DropShadow());
        });

        setOnMouseExited(e-> {
            setEffect(null);
        });
    }
}
