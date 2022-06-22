<?php
session_start();
?>
<?php
if($_SESSION["username"]) {
?>
Welcome <?php echo $_SESSION["username"]; ?>. Click here to <a href="logout.php" tite="Logout">Logout.
<html>
  <body>
    <br>
    <a >Look at the animals available for adoption here:</a><br>
    <a href="Animals.html"></a><a href="http://people.eecs.ku.edu/~j863l378/647Project/Animals.html" title="Animals">Animals</a><br>
    <a >Make an adoption request here:</a><br>
    <a href="AdoptReq.html"></a><a href="http://people.eecs.ku.edu/~j863l378/647Project/AdoptReq.html" title="Adoption Request">Adoption Request</a><br>
    <a >Add an adoptable animal here:</a><br>
    <a href="AdoptReq.html"></a><a href="http://people.eecs.ku.edu/~j863l378/647Project/AddAnimal.html" title="Add Animal">Add Animal</a><br>

<?php
}else echo "<h1>Please login first .</h1>";
?>
</body>
</html>
