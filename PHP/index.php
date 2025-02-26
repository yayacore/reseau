<?php
$prenom = "Massinissa";
$age = 24;
$metier = "serrurier";
$photo_url = "https://avatars.githubusercontent.com/u/34664499?v=4";
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">

    <title>Massi</title>

<style>

* {
    background-color: red;
    color: white;
}

.fond {
    display: flex;
    flex-direction: column;
    align-items: center;
    justify-content: center;
    border: dotted 4px;
    margin-top: 5%;
    margin-left: 30%;
    margin-right: 30%;
}           

.photo{
    padding-top: 15px;
    box-shadow: 800px;

</style>

</head>

<body>
    <div class="fond">

    <div class="photo">

        <img src= "https://avatars.githubusercontent.com/u/34664499?v=4" alt="photo">
        </div>
    
        <h1>Je suis <?= $prenom ?></h1>
        <p>programmeur à mes heures perdues</p>
        <p><?= $age ?> ans </p>
        <p><?= $metier ?></p>
    </div>



    
</body>
</html>