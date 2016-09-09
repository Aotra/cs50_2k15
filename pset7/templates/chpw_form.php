<form action="chpw.php" method="post">
    <fieldset>
        <div class="form-group">
        <input name="username" value=
        <?php
        $user= query("SELECT * FROM users WHERE id=?", $_SESSION["id"]);
        echo($user[0]['username']);
        ?>
        type="text"/>
       </div>
        <div class="form-group">
            <input autofocus name = "oldpassword" placeholder = "Old Passsword" type = "password"  />
            </div>
             <div class="form-group">
            <input name= "password" placeholder = "New Passsword" type = "password"/>
            </div>
             <div class="form-group">
            <input name= "confirmation" placeholder = "Confirmation" type = "password"/>
            </div>
             <div class="form-group">
            <button type="submit" class="btn btn-default">Change password</button>
              </div>
        </fieldset>
</form>
<div>
 </div>
<a href="javascript:history.go(-1);">Back</a>
