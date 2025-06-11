<?php
include 'db.php';

if (isset($_GET['rollno'])) {
    $rollno = $_GET['rollno'];

    $sql = "DELETE FROM table1 WHERE rollno = $rollno";

    if ($conn->query($sql) === TRUE) {
        echo "Record deleted successfully.<br><a href='index.php'>Back to Table</a>";
    } else {
        echo "Error deleting record: " . $conn->error;
    }

    $conn->close();
} else {
    echo "Invalid request.";
}
header("Location: index.php");
exit;
?>
