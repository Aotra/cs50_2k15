<div>                   
    <table class="table table-striped">
    <tbody>
        <?php
            
            
            foreach($positions as $position)
            {
                print("<tr>");
                 print("<td>" ."Name: ". $position["name"] ."</td>");
                print("<td>" ."Symbol: ". $position["symbol"] ."</td>");
                print("<td>" ."Price: ". number_format($position["price"],2) ."</td>");               
                print("</tr>");
            }
            
               ?> 
      </tbody>                     
    </table>
    </div> 
    <a href="javascript:history.go(-1);">Back</a>
