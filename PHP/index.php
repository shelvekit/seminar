<?php
include 'db.php';

$sql = "SELECT * FROM table1";
$result = $conn->query($sql);
?>

<!DOCTYPE html>
<html>
<head>
    <title>Student Table</title>
    <style>
    
    </style>
</head>
<body>
    <h2>Student Data</h2>
    <table border="1" cellpadding="10">
        <tr>
            <th>Roll No</th>
            <th>Name</th>
            <th colspan="2">Actions</th>
        </tr>

        <?php
        if ($result->num_rows > 0) {
            while($row = $result->fetch_assoc()) {
                echo "<tr>
                        <td>" . $row["rollno"] . "</td>
                        <td>" . $row["name"] . "</td>
                        <td><a href='delete.php?rollno=" . $row["rollno"] . "' onclick='return confirm(\"Are you sure?\")'>Delete</a></td>
                        <td><a href='edit.php?rollno=" . $row["rollno"] . "'>Edit</a></td>
                    </tr>";

            }
        } else {
            echo "<tr><td colspan='2'>No data found</td></tr>";
        }
        $conn->close();
        ?>

        </table>

        <a href="insert.php">insert data</a>


</body>
</html>
