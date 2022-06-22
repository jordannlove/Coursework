<?php
    session_start();
    $message="";
    if(count($_POST)>0) {
        $con = mysqli_connect("mysql.eecs.ku.edu", "katielucas", "oghe7yoL","katielucas") or die('Unable To connect');
        $result = mysqli_query($con,"SELECT * FROM User WHERE username='" . $_POST["username"] . "' and password = '". $_POST["password"]."'");
        $row  = mysqli_fetch_array($result);
        if(is_array($row)) {
        $_SESSION["username"] = $row['username'];
        $_SESSION["password"] = $row['password'];
        } else {
         $message = "Invalid Username or Password!";
        }
    }
    if(isset($_SESSION["username"])) {
    header("location: index.php");
    }
?>
<html>
<head>
<title>User Login</title>
</head>
<body>
<form name="frmUser" method="post" action="" align="center">
<div class="message"><?php if($message!="") { echo $message; } ?></div>
<h3 align="center">Welcome to the Adoption Website!</br> Enter Login Info Below</h3>
 Username:<br>
 <input type="text" name="username">
 <br>
 Password:<br>
<input type="password" name="password">
<br><br>
<input type="submit" name="Login" value="Login"><br>
<a>Create an account here:</a><br>
<a href="CreateUser.html"></a><a href="http://people.eecs.ku.edu/~j226p732/647Project/CreateUser.html" title="Create User">Create User</a><br>
</form>
</body>
</html>
