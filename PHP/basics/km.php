<html>
    <head>
  <meta http-equiv="refresh"content="1">
    <style>
        body
        {
        background-color:purple;
        }
         p
        {
            text-align:center;
            margin-top:100px;
        }
        
</style>
    </head>
    <body>
    <p>
        <?php
        date_default_timezone_set("Asia/kolkata");
        echo date("h:i:sa");
        ?>
        </p>
  </body>
    
    </html>