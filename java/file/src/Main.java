import java.io.File;
import java.io.IOException;
import java.io.FileWriter;
import java.util.Scanner;
import java.io.FileNotFoundException;

public class Main {
    public static void main(String[] args){
        String filename = "motivation.txt";
        File file = new File(filename);
        FileWriter writer = null;
        Scanner reader = null;

        if(file.exists()){
            System.out.printf("This \"%s\" file exist\n", file.getName());
            System.out.printf("Location: %s\n", file.getAbsolutePath());
            System.out.printf("Size of \"%s\" is %d Byte(s)\n", file.getName(), file.length());

            if(file.canWrite()){
                System.out.println("\tThe file can be written");
                try {
                    writer = new FileWriter(file);
                    writer.append("If yesterday did not goes well, don't worry, today it wont be good\n");
                }
                catch (Exception e){
                    System.out.println("Something went wrong on writing");
                }
                finally {
                    System.out.println("\tFile was successfully written");
                    try {
                        if(writer != null) {
                            writer.close();
                        }
                    }catch (Exception e){
                        System.out.println("Error on closing file");
                    }
                }
            }
            else {
                System.out.println("\tThis file cannot be  written");
            }

            if(file.canRead()){
                System.out.println("\nThe file can be read");
                try{
                    reader = new Scanner(file);
                } catch (FileNotFoundException e){
                    System.out.println("File does not exist");
                }
                catch (Exception e){
                    System.out.println("Something went wrong on reading");
                }
                finally {
                    while (reader.hasNextLine()){
                        System.out.println(reader.nextLine());
                    }
                    try{
                        reader.close();
                    }catch (Exception e){
                        System.out.println("Error on closing reader");
                    }
                }
            }
            else {
                System.out.println("\tThis file cannot be read");
            }
        }
        else {
            System.out.println("The file does not exist");
            try {
                if (file.createNewFile()) {
                    System.out.println("File created successfully");
                } else
                    System.out.printf("Cannot create this \"%s\"\n", filename);
            }
            catch (IOException e){
                System.out.println("Error on create this file");
            }
            catch (Exception e){
                System.out.println("Something went wrong on creating a file");
            }
        }
    }
}