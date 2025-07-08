<!DOCTYPE html>
<html>
    <body>
        <?php
            echo '<link rel="stylesheet" href="./style.css">';
            if($_GET){
                $id = $_GET["id"];
                $name = $_GET["name"];
                $hex = $_GET["hex"];
            }

            $db = new SQLite3('database.sqlite');

            $add = $db->query("INSERT INTO colors VALUES ($id, '{$name}', '{$hex}')"); 
            
            var_dump($add); 
        
        ?>
        <h1> ADDED YOUR VALUE </h1>
        <button onclick="javascript:history.back()";>
            Go back
        </button>
        </body>
</html>