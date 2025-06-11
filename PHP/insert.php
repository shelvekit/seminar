<?php
include 'db.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $rollno = $_POST['rollno'];
    $name = $_POST['name'];

    $sql = "INSERT INTO table1 (rollno, name) VALUES ('$rollno', '$name')";

    if ($conn->query($sql) === TRUE) {
        echo "New record inserted successfully.<br><a href='index.php'>View Data</a>";
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }

    $conn->close();
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Insert Student</title>
</head>
<body>
    <h2>Insert Student Data</h2>
    <form method="POST" action="">
        <label>Roll No:</label>
        <input type="number" name="rollno" required><br><br>

        <label>Name:</label>
        <input type="text" name="name" required><br><br>

        <input type="submit" value="Insert">
    </form>
    <br>
    <a href="index.php">Back to Data</a>
</body>
</html>
