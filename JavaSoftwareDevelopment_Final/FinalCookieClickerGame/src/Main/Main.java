package Main;

import UI.UserInterface;
import javafx.application.Application;
import javafx.stage.Stage;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
        // Sets up primary stage
        UserInterface userInterface = new UserInterface();
        primaryStage = userInterface.getMainStage();
        primaryStage.show();
    }


    public static void main(String[] args) {
        launch(args);
    }
}
