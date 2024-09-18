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
Content-Type: text/plain; charset=ISO-8859-1

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

> Aca tengo lo de hoy que no me tomaba la sintaxis... Che, me olvide, te
> podria haber dado el librito de analisis numerico.
>
>
> Saludos,
> Diego
>
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
">Aca tengo lo de hoy que no me tomaba la sintaxis... Che, me olvide, te po=
dria haber dado el librito de analisis numerico.<br>
<br><br>Saludos,<br>Diego<br><br>#include &lt;iostream&gt;<br>using namespa=
ce std;<br>void h(string url) {<br>
=A0 cout &lt;&lt; url &lt;&lt; endl;<br>}<br>void g(string url, void (*h)(s=
tring)) {<br>=A0 h(url);<br>}<br>void f(string url, void (*g)(string, void =
(*h)(string))) {<br>=A0 g(url, h);<br>}<br>int main() {<br>=A0 f(&quot;<a h=
ref=3D"http://www.google.com/" target=3D"_blank">http://www.google.com/</a>=
&quot;, g);<br>

}<br><br>
</blockquote></div><br>

--000e0ce0b8721fe135049ee29930--