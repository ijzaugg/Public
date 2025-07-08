<!DOCTYPE html>
<html lang="en">

<head>
    <title>Printable View</title>
    <script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
    <style>
        body {background-color: white;}
        h1   {color: black;}
        #squareTable table {
            border-collapse: collapse;
            margin: auto;
        }

        #squareTable table td {
            border: 1px solid black;
            height: 38px;
            width: 38px;
        }

        #colorTable table {
            border-collapse: collapse;
            margin: auto;
            width: 90%;
        }

        #colorTable table td {
            border: 1px solid black;
        }
    </style>

    <?php
        $table_size = $_GET['rowcol'];
        $color_num = $_GET['color_num'];
    ?>

    <script type="text/javascript">
        const row_col = <?php echo $table_size; ?>;
        console.log(row_col);

        const color_rows = <?php echo $color_num; ?>;
        console.log(color_rows);
    </script>

    <script src="tables.js"></script>
</head>

<body>
    <H1> <img class='logo' src='./extras/bwLogo.PNG' alt="Team Logo" width= 80px> ChromaCreate  </H1>
        <hr>
    <h3>Table 1</h3>
    <div id='colorTable'>
    </div>
    <br><br>
    <h3>Table 2</h3>
    <div id='squareTable'>
    </div>

</body>

</html>