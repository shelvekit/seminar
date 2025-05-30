<html>
  <body>
    <?php
          $age = 10 ;
          
          if($age > 18){
            echo("You Are Eligible For Voting.");
          }
           else{
            echo("You Are NOT Eligible For Voting. <br> Come after ". (18-$age) . " years.");
          }
                  
    ?>
       
  </body>
</html>