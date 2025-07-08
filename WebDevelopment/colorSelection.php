<!DOCTYPE html>
<html lang="en">
    <head>
        <?php include './head.php'; ?>
        <?php include './database.sqlite'; ?>
        <title>Color Selection</title>
    </head>

    <body>
        <?php

        $myPDO = new PDO('sqlite:/s/chopin/g/under/macke/local_html/team31/database.sqlite');
        
        ?>
        <form method= "get" action = "./add.php">
            <div class="question-container">
                    <h5>Add a color:</h5>
                    <h5>Id:<h5>
                        <div>
                            <input type="text" id="id" name="id"/>
                        </div>
                    <h5>Name:</h5>
                        <div>
                            <input type="text" id="name" name="name"/>
                        </div>
                    <h5>Hex:</h5>
                        <div>
                            <input type="text" id="hex" name="hex"/>
                        </div>
                    <input type="submit" name="submit" class= "button button1" value="Submit"><br><br>
            </div>
        </form>
    </body>
</html>