/*

    Example1

    mess with callbacks
    Diego Gavinowich <gdiego@gmail.com> 19 de marzo de 2011, 22:54
    Para: Alexis Jawtuschenko <alexis.jawtuschenko@gmail.com>
    <?php
    class A {
        public static function bajar($url, $callback) {
            $callback($url, array("A", "yabaje"));
        }
        public static function yabaje($url) {
            echo "$url\n";
        }
    };
    function yaesta($url, $callback) {
        $callback[0]::$callback[1]($url);
    }
    A::bajar('http://www.google.com/', "yaesta");
*/


/*

    Example2

    Authentication-Results: mr.google.com; spf=pass (google.com: domain of gdiego@gmail.com designates 10.216.67.143 as permitted sender) smtp.mail=gdiego@gmail.com; dkim=pass header.i=gdiego@gmail.com
    Received: from mr.google.com ([10.216.67.143])
            by 10.216.67.143 with SMTP id j15mr2646914wed.60.1300595975649 (num_hops = 1);
            Sat, 19 Mar 2011 21:39:35 -0700 (PDT)
    DKIM-Signature: v=1; a=rsa-sha256; c=relaxed/relaxed;
            d=gmail.com; s=gamma;
            h=domainkey-signature:mime-version:in-reply-to:references:date
             :message-id:subject:from:to:content-type;
            bh=BHmFRTrxa/H8tkMa7CrCsIM0GJuPunYUFvB+atsBrfo=;
            b=cRy4NJFBGNeOBiephBybVXavwjDlJhPHMet9jqxMzi3BnXZXrP59+YOjjlcLzYTYPB
             A1WtStbjqxim73RZKEfWfq4uCvWPSSpr/Ouxup+y5jr/tFm+D/VO31E7vn/QhakgvSx7
             tLfWwXpsTyvKTw855MvhSIVY2iJlQMpMbYuMQ=
    DomainKey-Signature: a=rsa-sha1; c=nofws;
            d=gmail.com; s=gamma;
            h=mime-version:in-reply-to:references:date:message-id:subject:from:to
             :content-type;
            b=qHx2q3qeYqN0k38WYmK9iaeRh2ZOAWqxE41UgvU3EUvLEUg34zve9MEhiQOvI2SpBC
             Qm59LCE4lsilTvAJDYVsG0pCqRMdCbG2EG8BgM5Ni9ti1T/9lMr0QpStL/s5+BcK3VI4
             r92BodUpar66o6wkJwE0dfZ2EkO22Us3KOpzE=
    MIME-Version: 1.0
    Received: by 10.216.67.143 with SMTP id j15mr2646914wed.60.1300595975643; Sat,
     19 Mar 2011 21:39:35 -0700 (PDT)
    Received: by 10.216.221.223 with HTTP; Sat, 19 Mar 2011 21:39:35 -0700 (PDT)
    In-Reply-To: <AANLkTinyuoJ_ckmk8wvwdvf7YNfpGigTvFsS4Zn9n+L8@mail.gmail.com>
    References: <AANLkTinyuoJ_ckmk8wvwdvf7YNfpGigTvFsS4Zn9n+L8@mail.gmail.com>
    Date: Sun, 20 Mar 2011 01:39:35 -0300
    Message-ID: <AANLkTim1=D1_uObgHpkipK+DMwV7_E+d0cqWhMvdW_bQ@mail.gmail.com>
    Subject: Re: Al fin :-)
    From: Diego Gavinowich <gdiego@gmail.com>
    To: Alexis Jawtuschenko <alexis.jawtuschenko@gmail.com>
    Content-Type: multipart/alternative; boundary=000e0ce0b8721fe135049ee29930

    --000e0ce0b8721fe135049ee29930

    Se entiende mejor asi (sin pisar los nombres de las funciones).

    #include <iostream>
    using namespace std;
    void h(string url) {
      cout << url << endl;
    }
    void g(string url, void (*hh)(string)) {
      hh(url);
    }
    void f(string url, void (*gg)(string, void (*hh)(string))) {
      gg(url, h);
    }
    int main() {
      f("http://www.google.com/", g);
    }


    2011/3/20 Diego Gavinowich <gdiego@gmail.com>

    > Aca tengo lo de hoy que no me tomaba la sintaxis

    > #include <iostream>
    > using namespace std;
    > void h(string url) {
    >   cout << url << endl;
    > }
    > void g(string url, void (*h)(string)) {
    >   h(url);
    > }
    > void f(string url, void (*g)(string, void (*h)(string))) {
    >   g(url, h);
    > }
    > int main() {
    >   f("http://www.google.com/", g);
    > }
    >
    >

    --000e0ce0b8721fe135049ee29930
    Content-Type: text/html; charset=ISO-8859-1
    Content-Transfer-Encoding: quoted-printable

    Se entiende mejor asi (sin pisar los nombres de las funciones).<br><br>#inc=
    lude &lt;iostream&gt;<br>using namespace std;<br>void h(string url) {<br>=
    =A0 cout &lt;&lt; url &lt;&lt; endl;<br>}<br>void g(string url, void (*hh)(=
    string)) {<br>
    =A0 hh(url);<br>}<br>void f(string url, void (*gg)(string, void (*hh)(strin=
    g))) {<br>=A0 gg(url, h);<br>}<br>int main() {<br>=A0 f(&quot;<a href=3D"ht=
    tp://www.google.com/">http://www.google.com/</a>&quot;, g);<br>}<br><br><br=
    ><div class=3D"gmail_quote">
    2011/3/20 Diego Gavinowich <span dir=3D"ltr">&lt;<a href=3D"mailto:gdiego@g=
    mail.com">gdiego@gmail.com</a>&gt;</span><br><blockquote class=3D"gmail_quo=
    te" style=3D"margin:0 0 0 .8ex;border-left:1px #ccc solid;padding-left:1ex;=
    ">Aca tengo lo de hoy que no me tomaba la sintaxis

    #include &lt;iostream&gt;<br>using namespa=
    ce std;<br>void h(string url) {<br>
    =A0 cout &lt;&lt; url &lt;&lt; endl;<br>}<br>void g(string url, void (*h)(s=
    tring)) {<br>=A0 h(url);<br>}<br>void f(string url, void (*g)(string, void =
    (*h)(string))) {<br>=A0 g(url, h);<br>}<br>int main() {<br>=A0 f(&quot;<a h=
    ref=3D"http://www.google.com/" target=3D"_blank">http://www.google.com/</a>=
    &quot;, g);<br>

    }
*/

/*

    Example3
    
    Perdon, lei re tarde... Espero que sirva, igual todo esto es medio falso ahora creo. Hay ciertas arquitecturas que te dejan direccionar a mas de 2^bits basicamente mandando la direccion en dos ciclos o cosas asi... O sea, no es del todo cierto (segun entiendo) que si tenes 30 bits solo podes direccionar a 2^30 cosas.

    Tampoco es cierto que un sistema operativo de 32 bits solo puede soportar 4GB (o un poco menos realmente) de memoria. El sistema operativo podria usar mas de una palabra para direccionar (kernel PAE: http://en.wikipedia.org/wiki/Physical_Address_Extension) y meter eso en el bus o mandarlo en varios ciclos si es soportado por la arquitectura.

    Lo que si es cierto con un sistema de 32 bits usando kernel PAE es que cada proceso puede usar hasta 4GB de memoria pero eso es un tema de software y seguro se podria evitar tambien (de hecho, el sistema operativo es el unico proceso que no lo cumple en esa situacion o sea que como poderse ;-)).

    Saludos,
    Diego


    2012/5/4 Alexis Jawtuschenko <alexis.jawtuschenko@gmail.com>

        7:54 PM me: recien lei las preguntas
          a ver si me acuerdo algo jeje
            5 minutes
        8:00 PM me: por lo que me acuerdo seria algo asi
          pero podria estar mal
        8:01 PM si tenes 4096MB que son 2^12MB
          y la palabra es de 2^5 = 32 bits
        8:03 PM 4096MB = 2^12 * 2^20 * 8 bits / 2^5 bits = 2^30 bits ... o sea, 30 bits en el bus
        8:04 PM si pones dos mas es 32 , direccionas a byte y se llama intel
        4GB
          el 25 es basicamente la misma cosa 3 veces
        8:05 PM 2GB = 2*2^30*8 bits
          dividis por 16 (2^4) y te queda 2^30 de nuevo
          o sea, 30 bits
        8:06 PM 8GB = 2^3*2^30*8 = 2^36 bits, la palabra de 8 bytes que es 8 * 8 = 2^6 bits
          te queda 30 otra vez
        8:07 PM 512 * 2^20 * 8 = 2^32 que dividido 8 es 2^29
          o sea, el ultimo da 29 bits parece
          estoy haciendo las cuentas mentalmente jeje , pero vos sos groso doctor en matematica asi que si le pifie te vas a dar cuenta :)
          el 26 dice
        8:08 PM direcciones de 24 bits y palabras de 64
          o sea, podes apuntar a 2^24 cosas de 2^6 bits
          2^30 bits de capacidad = 2^7MB
        8:09 PM 1GB = 2^10 MB = 2^20 KB = 2^30 B
        8:10 PM b) 2^20 direcciones de memoria y palabra de 8 bytes.
          tenes 2^20*2^3*8 bits = 2^26 bits = 8MB
        8:11 PM c) 2^24 * 2^5 bits = 2^29 bits = 2^6 MB = 64MB
*/
