<?php
header( 'Location: https://nitindinnu.github.io/home_automation_project/ ) ;

$file = "buttonStatus.txt";
$handle = fopen($file,'w+');
if (isset($_POST['LON']))
{
$onstring = "LON";
fwrite($handle,$onstring);
fclose($handle);
print "
<html>
<body>
<title> KNRR </title>

<style type=text/css>
h1{
        padding-left: 300px;
}
h2{
        position: absolute;
        top: 100px;
        left: 450px;
}
</style>
<h1>Internet of Things Implementation</h2>

<h2> LIGHT ON </h2>
</body>
</html>
";
}

else if(isset($_POST['LOFF']))
{
$offstring = "LOFF";
fwrite($handle, $offstring);
fclose($handle);
print "
<html>
<body>
<title> KNRR </title>
<style type=text/css>
h1{
        padding-left: 300px;
}
h2{
        position: absolute;
        top: 100px;
        left: 450px;
}
</style>
<h1>Internet of Things Implementation</h2>
<h2> LIGHT OFF </h2>
</body>
</html>
";
}

else if(isset($_POST['BON']))
{
$offstring = "BON";
fwrite($handle, $offstring);
fclose($handle);
print "
<html>
<body>
<title> KNRR </title>
<style type=text/css>
h1{
        padding-left: 300px;
}
h2{
        position: absolute;
        top: 100px;
        left: 450px;
}
</style>
<h1>Internet of Things Implementation</h2>
<h2> BULB ON </h2>
</body>
</html>
";
}

else if(isset($_POST['BOFF']))
{
$offstring = "BOFF";
fwrite($handle, $offstring);
fclose($handle);
print "
<html>
<body>
<title> KNRR </title>
<style type=text/css>
h1{
        padding-left: 300px;
}
h2{
        position: absolute;
        top: 100px;
        left: 450px;
}
</style>
<h1>Internet of Things Implementation</h2>
<h2> BULB OFF </h2>
</body>
</html>
";
}



else if(isset($_POST['ALLON']))
{
$offstring = "ALLON";
fwrite($handle, $offstring);
fclose($handle);
print "
<html>
<body>
<title>KNRR </title>
<style type=text/css>
h1{
        padding-left: 300px;
}
h2{
        position: absolute;
        top: 100px;
        left: 450px;
}
</style>
<h1>Internet of Things Implementation</h2>
<h2> ALL DEVICES ON </h2>
</body>
</html>
";
}

else if(isset($_POST['ALLOFF']))
{
$offstring = "ALLOFF";
fwrite($handle, $offstring);
fclose($handle);
print "
<html>
<body>
<title> KNRR </title>
<style type=text/css>
h1{
        padding-left: 300px;
}
h2{
        position: absolute;
        top: 100px;
        left: 450px;
}
</style>
<h1>Internet of Things Implementation</h2>
<h2> ALL DEVICES OFF </h2>
</body>
</html>
";
}

?>