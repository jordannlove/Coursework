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
  $id = $_POST["id"];
  $name = $_POST["name"];
  $cost = $_POST["cost"];
  $age = $_POST["age"];
  $species = $_POST["species"];

  if($id=="")
  {
    echo"The ID is blank, try again.</br>";
  }
  else if($name=="")
  {
    echo"The name is blank, try again.</br>";
  }
  else if($cost=="")
  {
    echo"The cost is blank, try again.</br>";
  }
  else if($age=="")
  {
    echo"The age is blank, try again.</br>";
  }
  else if($species=="")
  {
    echo"The species is blank, try again.</br>";
  }
  else
  {
    $sql = "INSERT INTO Animals (id, name, cost, age, species) VALUES ('$id', '$name', '$cost', '$age', '$species')";
    echo "<p>You have requested to intake a $species with the id $id</p>";
    $result = mysqli_query($mysqli,$sql);
    // echo "<p>Information of animal requested:</p>";
    // $result5 = mysqli_query($mysqli, "SELECT * FROM Animals WHERE id='$id'");
    // echo '<table border=\"1\">';
    // echo"<td>id</td>";
    // echo"<td>name</td>";
    // echo"<td>cost</td>";
    // echo"<td>age</td>";
    // echo"<td>species</td>";
    // while($row = mysqli_fetch_array($result5))
    // {
    // echo "<tr>";
    // echo "<td>".$row['id']."</td>";
    //   echo "<td>".$row['name']."</td>";
    //   echo "<td>".$row['cost']."</td>";
    //   echo "<td>".$row['age']."</td>";
    //   echo "<td>".$row['species']."</td>";
    // echo "</tr>";
    // }
    // echo '</table>';
    // $result = mysqli_query($mysqli,$sql);
    // echo "<p>Ids of all adoption requests from this user:</p>";
    // $result6 = mysqli_query($mysqli, "SELECT distinct id FROM AdoptionRequest WHERE username='$username'");
    // echo '<table border=\"1\">';
    // while($row = mysqli_fetch_array($result6))
    // {
    // echo "<tr>";
    // echo "<td>".$row['id']."</td>";
    // echo "</tr>";
    // }
    // echo '</table>';
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
