
<?php
session_start();
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
  $username = $_SESSION["username"];
  $password = $_SESSION["password"];
  $id = $_POST["id"];

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
    $query = "SELECT username, password FROM User WHERE username='$username' AND password='$password'";
    $result = mysqli_query($mysqli,$query);
    $query3 = "SELECT id FROM Animals WHERE id='$id'";
    $result3 = mysqli_query($mysqli,$query3);
    $query7 = "SELECT username FROM AdoptionRequest WHERE id='$id' AND username='$username'";
    $result7 = mysqli_query($mysqli,$query7);

    if($result->num_rows == 0)
    {
      echo "Invalid username or password, try again</br>";
    }
    else if($result3->num_rows == 0 )
    {
      echo "Invalid animal id, try again</br>";
    }
    else if($result7->num_rows == 0)
    {
      $sql = "INSERT INTO AdoptionRequest (username, id) VALUES ('$username', '$id')";
      echo "<p>$username has requested to adopt animal with the id $id</p>";

      echo "<p>Information of animal requested:</p>";
      $result5 = mysqli_query($mysqli, "SELECT * FROM Animals WHERE id='$id'");
      echo '<table border=\"1\">';
      echo"<td>id</td>";
      echo"<td>name</td>";
      echo"<td>cost</td>";
      echo"<td>age</td>";
      echo"<td>species</td>";
      while($row = mysqli_fetch_array($result5))
      {
      	echo "<tr>";
      	echo "<td>".$row['id']."</td>";
        echo "<td>".$row['name']."</td>";
        echo "<td>".$row['cost']."</td>";
        echo "<td>".$row['age']."</td>";
        echo "<td>".$row['species']."</td>";
      	echo "</tr>";
      }
      echo '</table>';
      $result = mysqli_query($mysqli,$sql);
      echo "<p>Ids of all adoption requests from this user:</p>";
      $result6 = mysqli_query($mysqli, "SELECT distinct id FROM AdoptionRequest WHERE username='$username'");
      echo '<table border=\"1\">';
      while($row = mysqli_fetch_array($result6))
      {
      	echo "<tr>";
      	echo "<td>".$row['id']."</td>";
        echo "<td>".$row['username']."</td>";
      	echo "</tr>";
      }
      echo '</table>';
    }
    else
    {
      echo "User already requested this animal id, try again</br>";
      echo "<p>Ids of all adoption requests from this user:</p>";
      $result6 = mysqli_query($mysqli, "SELECT distinct id FROM AdoptionRequest WHERE username='$username'");
      echo '<table border=\"1\">';
      while($row = mysqli_fetch_array($result6))
      {
      	echo "<tr>";
      	echo "<td>".$row['id']."</td>";
      	echo "</tr>";
      }
      echo '</table>';
      echo "<p>All the cats you have requested:</p>";
      $result10 = mysqli_query($mysqli, "SELECT distinct Animals.id FROM AdoptionRequest, Animals WHERE username='$username' AND species='cat' AND AdoptionRequest.id = Animals.id");
      echo '<table border=\"1\">';
      while($row = mysqli_fetch_array($result10))
      {
      	echo "<tr>";
      	echo "<td>".$row['id']."</td>";
      	echo "</tr>";
      }
      echo '</table>';
	    echo "<p>All the dogs you have requested:</p>";
      $result11 = mysqli_query($mysqli, "SELECT distinct Animals.id FROM AdoptionRequest, Animals WHERE username='$username' AND species='dog' AND AdoptionRequest.id = Animals.id");
      echo '<table border=\"1\">';
      while($row = mysqli_fetch_array($result11))
      {
      	echo "<tr>";
      	echo "<td>".$row['id']."</td>";
      	echo "</tr>";
      }
      echo '</table>';

    }

  }
  $query = "SELECT username";
  if ($result = $mysqli->query($query))
  {
   /* fetch associative array */
   while ($row = $result->fetch_assoc())
   {
     printf ("%s (%s)\n", $row["username"]);
   }
   /* free result set */
   $result->free();
  }
  /* close connection */
  $mysqli->close();
  ?>
