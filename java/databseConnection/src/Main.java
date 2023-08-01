import java.sql.*;

public class Main {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/users";
        String username = "root";
        String password = "", sql, user = "tembe";

        try{
            sql = "INSERT INTO user (username) VALUES (?)";

            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection conn = DriverManager.getConnection(url, username, password);

            Statement state = conn.createStatement();
            PreparedStatement preState = conn.prepareStatement(sql);
            preState.setString(1, user);
            int res = preState.executeUpdate();
            System.out.println(res);
            /*
            ResultSet res = state.executeQuery("SELECT * FROM user;");
            System.out.println(res.next());

            try {
                state.executeUpdate(sql);

            } catch (SQLIntegrityConstraintViolationException e){
                System.out.println("Username already exist");
            }
            catch (Exception e){
                System.out.println(e);
            }
            */
            ResultSet result = state.executeQuery("SELECT * FROM user");
            while(result.next()){
                System.out.println(result.getInt(1) + " " + result.getString(2) + " " + result.getString(3));
            }
            conn.close();
        } catch (Exception e){
            System.out.println("Error on creating connection " + e);
        }
    }
}