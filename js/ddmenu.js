<!--//--><![CDATA[//><!--

sfHover = function() {
    var uls = document.getElementsByTagName("UL");
    for (var i = 0; i < uls.length; i++) {
        if (uls[i].getAttribute("className") == "ddmenu") {
            var lis = uls[i].getElementsByTagName("LI");
            for (var j = 0; j < lis.length; j++) {
                lis[j].onmouseover = function() {
                    this.className += " sfhover";
                }
                lis[j].onmouseout=function() {
                    this.className = this.className.replace(
                        new RegExp(" sfhover\\b"), "");
                }
            }
        }
    }
}
if (window.attachEvent) {
    window.attachEvent("onload", sfHover);
}

//--><!]]>

