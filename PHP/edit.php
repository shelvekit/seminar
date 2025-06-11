<?php
include 'db.php';

if (isset($_GET['rollno'])) {
    $rollno = $_GET['rollno'];
    
    // Fetch current data
    $result = $conn->query("SELECT * FROM table1 WHERE rollno = $rollno");

    if ($result->num_rows == 1) {
        $row = $result->fetch_assoc();
    } else {
        echo "Record not found!";
        exit;
    }
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $rollno = $_POST['rollno'];
    $name = $_POST['name'];

    $sql = "UPDATE table1 SET name='$name' WHERE rollno=$rollno";

    if ($conn->query($sql) === TRUE) {
        header("Location: index.php");
        exit;
    } else {
        echo "Error updating record: " . $conn->error;
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Edit Student</title>
</head>
<body>
    <h2>Edit Student Data</h2>
    <form method="POST">
        <label>Roll No (Read-only):</label>
        <input type="number" name="rollno" value="<?php echo $row['rollno']; ?>" readonly><br><br>

        <label>Name:</label>
        <input type="text" name="name" value="<?php echo $row['name']; ?>" required><br><br>

        <input type="submit" value="Update">
    </form>
    <br>
    <a href="index.php">Back to Table</a>
</body>
</html>
