<!DOCTYPE html>
<html lang="en">

<head>
    <?php include './head.php'; ?>
    <title>Main Page</title>
</head>

<body>
    <H1> <img class='logo' src='./extras/logo_3.png' alt="Team Logo" width= 80px> ChromaCreate  </H1>
    <!--Populate Navbar-->
    <div class="navbar">
        <?php include './navbar.php'; ?>
    </div>
    <main>
        <?php
        #First display
        $page = 'home.php';

        if ($_SERVER['REQUEST_METHOD'] === 'POST') {
            if(isset($_POST['page'])){
                $page = $_POST['page'];
            }
        } elseif ($_SERVER['REQUEST_METHOD'] === 'GET' && isset($_GET['rowcol'])) {
            $page = 'ccg.php';
        }

        include $page;
        include './footer.php';
        ?>
    </main>
</body>

</html>