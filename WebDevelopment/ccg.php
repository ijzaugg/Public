<!DOCTYPE html>
<html lang="en">

<head>
    <title>Color Coordinate Generation</title>
    <script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>

    <?php
    $table_size = -1;
    $color_num = -1;

    if (isset($_GET["rowcol"])) {
        $table_size = $_GET["rowcol"];

        if ($table_size > 26 || $table_size < 1) {
            echo "<div class='error'>Please enter a number between 1 and 26 in the rows and columns textbox before resubmitting.</div>";
            $table_size = -1;
        }
        if (!is_numeric($table_size)) {
            echo "<div class='error'>Please enter a number value for rows and columns in the textbox before resubmitting.</div>";
            $table_size = -1;
        }
    }

    if (isset($_GET["colors"])) {
        $color_num = $_GET["colors"];

        if ($color_num > 10 || $color_num < 1) {
            echo "<div class='error'>Please enter a number between 1 and 10 in the color textbox before resubmitting.</div>";
            $color_num = -1;
        }
        if (!is_numeric($color_num)) {
            echo "<div class='error'>Please enter a number value for color choice in the textbox before resubmitting.</div>";
            $color_num = -1;
        }
    }
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
    <h2>Table Input</h2>
    <div id="table_input">
        <form method="get" action="index.php">
            <input type="hidden" name="page" value="ccg.php">
            <p class="input_prompts">How many rows and columns would you like in your table?</p>
            <label class="input_prompts" for="rowcol_pick">Choose a number between 1 and 26: </label>
            <input class="input_box" type="text" name="rowcol" id="rowcol_pick">

            <p class="input_prompts">How many colors would you like to choose from?</p>
            <label class="input_prompts" for="color_pick">Choose a number between 1 and 10: </label>
            <input class="input_box" type="text" name="colors" id="color_pick"><br>
            <br> <br>
            <input type="submit" id="submit_btn">
        </form>
    </div>

    <h3>Table 1</h3>
    <div id='colorTable'>
    </div>
    <h3>Table 2</h3>
    <div id='squareTable'>
    </div>

    <br><br>
    <?php
    echo '<form method="POST" action="./printview.php?rowcol='.urlencode($table_size).'&color_num='.urlencode($color_num).'" target="_blank">
        <input class="printButton" type="submit" value="Printable View">
        </form>';
    ?>
</body>

</html>