<?php
# Use: 'Name of page to be displayed on navbar' => 'page.php',
# Add pages in order of display
$links = array(
    'Home' => 'home.php',
    'About' => 'about.php',
    'Color Generator' => 'ccg.php',
    'Color Selection' => 'colorSelection.php'
);

# Populate Navbar
foreach($links as $page => $link) {
    echo '<form method="post" action="index.php" class="nav-item">';
    echo '<input type="hidden" name="page" value="./' . $link . '">';
    echo '<button type="submit" class="nav-button">' . $page . '</button>';
    echo '</form>';
}
?>