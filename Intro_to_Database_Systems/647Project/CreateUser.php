
<?php
error_reporting(E_ALL);
ini_set("display_errors", 1);
$mysqli = new mysqli("mysql.eecs.ku.edu", "katielucas", "oghe7yoL",
"katielucas");
/* check connection */
if ($mysqli->connect_errno)
{
 printf("Connect failed: %s\n", $mysqli->connect_error);
 exit();
}
  $username = $_POST["username"];
  $password = $_POST["password"];

  if($username=="")
  {
    echo"Your username is blank, try again.</br>";
  }
  else if($password=="")
  {
    echo"Your password is blank, try again.</br>";
  }

  else
  {
    $query = "SELECT username FROM User WHERE username='$username'";
    $result = mysqli_query($mysqli,$query);

    if($result->num_rows != 0)
    {
      echo "Invalid username, this one already exists, try again</br>";
    }
    else
    {
      $sql = "INSERT INTO User (username, password) VALUES ('$username', '$password')";
      $result = mysqli_query($mysqli,$sql);
      echo "New User Saved!</br>Return to http://people.eecs.ku.edu/~j226p732/647Project/login.php to login</br>";
    }
  }
  $query = "SELECT username";
  if ($result = $mysqli->query($query))
  {
   /* fetch associative array */
   while ($row = $result->fetch_assoc())
   {
     printf ("%s (%s)\n", $row["user_id"]);
   }
   /* free result set */
   $result->free();
  }
  /* close connection */
  $mysqli->close();
  ?>
