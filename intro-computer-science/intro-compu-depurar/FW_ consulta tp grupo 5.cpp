Delivered-To: alexis.jawtuschenko@gmail.com
Received: by 10.220.164.19 with SMTP id c19cs170313vcy;
        Tue, 14 Sep 2010 13:18:48 -0700 (PDT)
Received: by 10.213.7.9 with SMTP id b9mr420317ebb.58.1284495350968;
        Tue, 14 Sep 2010 13:15:50 -0700 (PDT)
Received-SPF: softfail (google.com: best guess record for domain of transitioning teofilo60@hotmail.com does not designate 65.54.246.166 as permitted sender) client-ip=65.54.246.166;
Received: by 10.208.8.6 with POP3 id 6mf900350eyh.22;
        Tue, 14 Sep 2010 13:15:50 -0700 (PDT)
X-Gmail-Fetch-Info: alexis_bj@hotmail.com 1 pop3.live.com 995 alexis_bj@hotmail.com
X-Message-Delivery: Vj0zLjQuMDt1cz0wO2w9MDthPTE=
X-Message-Status: n:0
X-SID-PRA: mateo astelarra <teofilo60@hotmail.com>
X-SID-Result: Pass
X-Message-Info: JGTYoYF78jEsDnYvAXDp22JVht1kDGdPSiKUF1bTrYT8VRt9Sg4oI8le0hYUZjzeyz3DbbSAG8t+ix5BcxE+wlJ4Ai/XTwfx
Received: from bay0-omc2-s30.bay0.hotmail.com ([65.54.246.166]) by bay0-imc1-s18.bay0.hotmail.com with Microsoft SMTPSVC(6.0.3790.2444);
	 Wed, 18 Jun 2008 13:07:06 -0700
Received: from BAY112-W9 ([64.4.26.109]) by bay0-omc2-s30.bay0.hotmail.com with Microsoft SMTPSVC(6.0.3790.3959);
	 Wed, 18 Jun 2008 13:06:57 -0700
Message-ID: <BAY112-W9CA24623E49BBB3B957A4BBAB0@phx.gbl>
Return-Path: teofilo60@hotmail.com
Content-Type: multipart/alternative;
	boundary="_15c8f27f-5517-440c-a29f-316f0490fc47_"
X-Originating-IP: [190.226.88.86]
From: mateo astelarra <teofilo60@hotmail.com>
To: Alexis Jawtuschenko <alexis_bj@hotmail.com>
Subject: FW: consulta tp grupo 5
Date: Wed, 18 Jun 2008 20:06:57 +0000
Importance: Normal
In-Reply-To: <E03C6CD6-4A40-496A-AEE4-A46FDD09BE2D@dc.uba.ar>
References: <008a01c8d0c3$9df30a10$6401a8c0@acer73d8bd810a>
 <CD697E1D-188F-40B8-BF8B-C4DF553975DE@dc.uba.ar>
 <BAY112-W22A881D356DF7DBD212F07BBAB0@phx.gbl>
 <E03C6CD6-4A40-496A-AEE4-A46FDD09BE2D@dc.uba.ar>
MIME-Version: 1.0
X-OriginalArrivalTime: 18 Jun 2008 20:06:57.0802 (UTC) FILETIME=[DCA626A0:01C8D17E]

--_15c8f27f-5517-440c-a29f-316f0490fc47_
Content-Type: text/plain; charset="iso-8859-1"
Content-Transfer-Encoding: quoted-printable


> From: dgorin@dc.uba.ar> Subject: Re: consulta tp grupo 5> Date: Wed, 18 J=
un 2008 00:36:34 -0300> To: teofilo60@hotmail.com> > hola, mateo> > la preg=
unta est=E1 muy bien. de alguna forma su problema viene de la > conjunci=F3=
n de los siguientes hechos:> > 1) los algoritmos recursivos que pensaron tr=
abajan sobre =E1rboles.> 2) un =E1rbol es un puntero a nodo.> 3) un diccion=
ario no es un =E1rbol, sino que contiene un =E1rbol.> > o sea, el m=E9todo =
contieneClave que escribieron es recursivo, pero > trabaja sobre diccionari=
os, no sobre =E1rboles y ah=ED se les rompe todo. > lo que yo les recomiend=
o es implementar funciones auxiliares > recursivas que trabajen sobre =E1rb=
oles e implementar los m=E9todos de > diccionario en t=E9rminos de esas fun=
ciones.> > si no se entiende lo que quiero decir, chiflen!> > saludos> dani=
el> > On Jun 17, 2008, at 11:33 PM, mateo astelarra wrote:> > > hola daniel=
:> >> > estuvimos implementando el tad diccionario, en private pusimos: un =
> > puntero a la raiz y una cantidad.(ordenariamos los nodos como un > > ar=
bol binario segun la clave).> > cada nodo tiene un puntero nodo izquierdo. =
un puntero a nodo > > derecho, una clave y un valor.> >> > pero muchos meto=
dos nos quedan recursivos:> > ejemplo:> >> > bool diccionario::contieneClav=
e(clave k)const> > {> > if ( this->raiz=3D=3DNULL)> > {> > return false;> >=
 }> > else if( this->raiz->clave=3D=3Dk)> > {> > return true;> > }> > else =
if( this->raiz->clave<k)> > {> > return (this->raiz->izquierdo).contieneCla=
ve(k);> > }> > else> > {> > return (this->raiz->derecho).contieneClave(k);>=
 > }> > }> >> >> > pero esto esta mal porq (this->raiz->izquierdo) es un pu=
ntero a > > nodo y le estamos aplicando un metodo para diccionarios.=BFcomo=
 hacemos?> >> > pense en definir una variable auxiliar de tipo diccionario =
que > > tenga como raiz al primer nodo de la izquierda. pero nose que > > c=
antidad meterle( le meti cero y compilo pero no estariamos > > respetando e=
l invariante de representacion)> >> > no se me ocurrio nada mas. pero casi =
todas las funciones nos > > quedaron de ese estilo.> > =BFhay manera de sal=
varlo o lo encaramos por otro lado?> >> > saludos> > gracias> > mateo> >> >=
 > From: dgorin@dc.uba.ar> > > Date: Tue, 17 Jun 2008 20:26:53 -0300> > > T=
o: flavia@bonomo.com.ar> > > CC: ic-alu@dc.uba.ar> > > Subject: Re: [ic-alu=
] clase del mi=E9rcoles y marcha> > >> > > Buenas> > >> > > Como creo que n=
o se desprende del mail de Flavia, aclaro que tampoco> > > va a haber labor=
atorio ma=F1ana. Vamos a correr la entrega del TP para> > > el mi=E9rcoles =
que viene.> > >> > > Saludos> > > Daniel> > >> > > pd: Seguimos respondiend=
o consultas por mail...> > >> > > On Jun 17, 2008, at 6:46 PM, Flavia Bonom=
o wrote:> > >> > > > Hola chicos,> > > >> > > > Ma=F1ana miercoles a las 15=
hs es la movilizaci=F3n a la Plaza de Mayo> > > > llamada por varias organi=
zaciones sociales.> > > >> > > > En particular, yo pienso ir a la marcha, y=
 por lo tanto> > > > no voy a dar clase de Introducci=F3n ni de L=F3gica qu=
e> > > > caen a la misma hora.> > > >> > > > Para aquellos que quieran sabe=
r (m=E1s o menos) los motivos por los> > > > cuales voy a la marcha y/o adh=
erir al texto, les paso un documento> > > > de un> > > > grupo> > > > indep=
endiente que llama a la movilizaci=F3n, entre los que estamos> > > > varios=
 docentes, graduados y estudiantes de Exactas.> > > >> > > > saludos,> > > =
> flavia> > > >> > > > > > ************************************************=
**********************> > > > *> > > >> > > > Por qu=E9 vamos a la plaza> >=
 > > (adhesiones a arte@centrocultural.coop)> > > >> > > > Hoy (por ma=F1an=
a mi=E9rcoles 18 de junio) a las 13 nos > > concentramos en> > > > Avenida =
de Mayo y Per=FA, en defensa de la democracia y en > > reclamo de> > > > ma=
yor distribuci=F3n de la riqueza y participaci=F3n popular.> > > >> > > > L=
o haremos desde nuestra propia identidad y sin ahorrar > > cr=EDticas al> >=
 > > Poder Ejecutivo Nacional, pero en respaldo de la institucionalidad> > =
> > democr=E1tica y de las medidas progresivas que enfurecieron a una > > n=
ueva> > > > derecha que usa la ret=F3rica del di=E1logo y el consenso y se =
> > envuelve en> > > > los s=EDmbolos nacionales mientras pretende mantener=
 sus > > privilegios.> > > > Con lock-out patronal y desabastecimiento no h=
ay vocaci=F3n de > > dialogo.> > > > Es imprescindible el levantamiento de =
las medidas de fuerza, y > > que el> > > > gobierno haga una amplia convoca=
toria a todos los sectores> > > > involucrados, para la discusi=F3n integra=
l de un nuevo modelo> > > > productivo.> > > >> > > > Somos miembros de org=
anizaciones sindicales como la CTA, CTERA, la> > > > Uni=F3n Obrera Metal=
=FArgica, CONADU; de movimientos como Tupac > > Amaru y> > > > Movimiento N=
acional Patria Grande; de organismos de derechos > > humanos> > > > como el=
 CELS, la Liga Argentina por los Derechos del Hombre, las> > > > Madres de =
Plaza de Mayo-L=EDnea Fundadora, la Asamblea Permanente > > por> > > > los =
Derechos Humanos; de peque=F1os empresarios, como la Asamblea de> > > > PYM=
ES y el Instituto Movilizador de Fondos Cooperativos; > > economistas> > > =
> del Plan F=E9nix; decanos y profesores universitarios, cient=EDficos e> >=
 > > investigadores; sacerdotes en opci=F3n por los pobres; dirigentes> > >=
 > pol=EDticos que demostramos la posibilidad de construir alternativas> > =
> > populares sin clientelas ni aparatos; intelectuales y artistas> > > > i=
ntegrantes del agrupamiento Carta Abierta y ciudadanos sin > > militancia> =
> > > partidaria ni institucional.> > > >> > > > No formamos parte del gobi=
erno. Objetamos la destrucci=F3n del > > INDEC y> > > > la construcci=F3n d=
el tren bala, la negativa a reconocer la > > personer=EDa> > > > de la CTA =
y la alianza con sectores de la mal llamada burgues=EDa> > > > nacional, qu=
e fue socia de los gobiernos neoliberales. > > Consideramos> > > > intolera=
ble el mantenimiento de altos niveles de hambre y > > exclusi=F3n en> > > >=
 uno de los grandes pa=EDses productores de alimentos del mundo.> > > >> > =
> > Pero la restauraci=F3n conservadora en marcha, con el impulso de un> > =
> > sector de la izquierda que imagina protagonizar una revoluci=F3n> > > >=
 agraria, no cuestiona los defectos sino los aciertos del > > gobierno, al>=
 > > > que intenta imponerle sus intereses econ=F3micos por encima del > > =
inter=E9s> > > > general, sin reparar en costos ni en m=E9todos. Cuestiona =
la> > > > reconstrucci=F3n de la autoridad del Estado luego del colapso de =
> > 2002,> > > > el saneamiento de la Corte Suprema de Justicia, el juicio =
a los> > > > responsables del Estado terrorista, el dr=E1stico descenso de =
la> > > > desocupaci=F3n, la recuperaci=F3n del r=E9gimen jubilatorio estat=
al, el> > > > establecimiento de un haber para las personas mayores de 70 >=
 > a=F1os que> > > > no ten=EDan ninguno, el aumento del presupuesto educat=
ivo, la > > creaci=F3n> > > > de un ministerio de ciencia y tecnolog=EDa, l=
a pol=EDtica exterior> > > > independiente, en asociaci=F3n con los gobiern=
os democr=E1ticos de> > > > Sudam=E9rica. No busca un avance sino un salto =
atr=E1s.> > > >> > > > Contra toda evidencia se acusa de autoritario y sobe=
rbio al primer> > > > gobierno que ha prohibido el uso de armas de fuego en=
 el > > control de> > > > manifestaciones y se moteja de represi=F3n violen=
ta al desalojo con> > > > guantes de seda de la ruta del MERCOSUR, por la q=
ue desde hace > > tres> > > > meses no se permite el tr=E1nsito de mercader=
=EDas, obligando a tirar> > > > millones de litros de leche y toneladas de =
frutas y verduras. > > De ese> > > > clima deslegitimador, parecido al que =
min=F3 la presidencia de > > Arturo> > > > Illia, participan en forma tan e=
ntusiasta como irreflexiva > > sectores de> > > > las clases medias urbanas=
 influidos por la cobertura > > tendenciosa de> > > > diarios y canales de =
televisi=F3n temerosos de que se democratice la> > > > comunicaci=F3n de ma=
sas.> > > >> > > > De esta crisis, no menos grave porque se la niegue, s=F3=
lo se > > sale con> > > > m=E1s democracia y m=E1s distribuci=F3n de la riq=
ueza. Para ello se > > impone> > > > una reforma impositiva integral, que g=
rave a todos los sectores > > que en> > > > estos a=F1os han tenido benefic=
ios extraordinarios, como la > > especulaci=F3n> > > > financiera, la miner=
=EDa y la pesca.> > > >> > > > =C9sa es la voz propia con la que hoy iremos=
 a la Plaza de Mayo, en> > > > defensa del valioso trayecto recorrido desde=
 mayo de 2003 y en > > demanda> > > > de su profundizaci=F3n, con mayor cal=
idad institucional y con la> > > > participaci=F3n popular.> > > >> > > >> =
> > > Jorge Aliaga, Carolina Vera, Juan Pablo> > > > Paz, Alberto Kornbliht=
t, Adri=E1n Paenza, Guillermo Dussel,> > > > Jose Olabe, Norberto Iusem, Es=
teban Hasson, Marcelo Frias, Roberto> > > > Etchenique, Julian Fernandez Bo=
nder, Guillermo Duran, Vera Brudny,> > > > Flavia Bonomo, Ana Menendez, Pab=
lo Paez, Ricardo Cabrera,> > > > Luciano Moffat, Leonardo Zayat, Dario Estr=
in, Silvina> > > > Ponce Dawson, Pablo Groisman, Agustin Petroni, Eduardo D=
vorkin, > > Diego> > > > Garbebersky, Ruth Rosenstein, Adali Pecci, Claudia=
 Perez Leiros,> > > > Marcos Mobbili, Mariano Camilo Gonzalez Lebrero, Hugo=
 Yasky, > > Mart=EDn> > > > Sabbatella, Horacio Verbitsky, Laura Conte, Jua=
n> > > > Gelman, Eduardo de la Serna, Abraham Gak, Carlos Heller, Horacio> =
> > > Gonz=E1lez,> > > > Nicol=E1s Casullo, Lilia Ferreyra,> > > > Ana Caco=
pardo, Victorio Paul=F3n, Stella Maldonado, Roberto > > Baradell,> > > > Ca=
rlos De Feo, Juan Carlos Junio, Juano Villafa=F1e, icente > > Battista,> > =
> > Alejandro Dolina> > > >> > > >> > > >> > > > __________________________=
_____________________> > > > ic-alu mailing list> > > > ic-alu@dc.uba.ar> >=
 > > https://listas.dc.uba.ar/cgi-bin/mailman/listinfo/ic-alu> > >> > > ___=
____________________________________________> > > ic-alu mailing list> > > =
ic-alu@dc.uba.ar> > > https://listas.dc.uba.ar/cgi-bin/mailman/listinfo/ic-=
alu> >> >> > =BFAburrido? Ingres=E1 ya y divertite como nunca en MSN Juegos=
. MSN Juegos>=20
_________________________________________________________________
Descarg=E1 ya gratis y viv=ED la experiencia Windows Live.
http://www.descubrewindowslive.com/latam/index.html=

--_15c8f27f-5517-440c-a29f-316f0490fc47_
Content-Type: text/html; charset="iso-8859-1"
Content-Transfer-Encoding: quoted-printable

<html>
<head>
<style>
.hmmessage P
{
margin:0px;
padding:0px
}
body.hmmessage
{
FONT-SIZE: 10pt;
FONT-FAMILY:Tahoma
}
</style>
</head>
<body class=3D'hmmessage'>
<BR><BR>&gt; From: dgorin@dc.uba.ar<BR>&gt; Subject: Re: consulta tp grupo =
5<BR>&gt; Date: Wed, 18 Jun 2008 00:36:34 -0300<BR>&gt; To: teofilo60@hotma=
il.com<BR>&gt; <BR>&gt; hola, mateo<BR>&gt; <BR>&gt; la pregunta est=E1 muy=
 bien. de alguna forma su problema viene de la <BR>&gt; conjunci=F3n de los=
 siguientes hechos:<BR>&gt; <BR>&gt; 1) los algoritmos recursivos que pensa=
ron trabajan sobre =E1rboles.<BR>&gt; 2) un =E1rbol es un puntero a nodo.<B=
R>&gt; 3) un diccionario no es un =E1rbol, sino que contiene un =E1rbol.<BR=
>&gt; <BR>&gt; o sea, el m=E9todo contieneClave que escribieron es recursiv=
o, pero <BR>&gt; trabaja sobre diccionarios, no sobre =E1rboles y ah=ED se =
les rompe todo. <BR>&gt; lo que yo les recomiendo es implementar funciones =
auxiliares <BR>&gt; recursivas que trabajen sobre =E1rboles e implementar l=
os m=E9todos de <BR>&gt; diccionario en t=E9rminos de esas funciones.<BR>&g=
t; <BR>&gt; si no se entiende lo que quiero decir, chiflen!<BR>&gt; <BR>&gt=
; saludos<BR>&gt; daniel<BR>&gt; <BR>&gt; On Jun 17, 2008, at 11:33 PM, mat=
eo astelarra wrote:<BR>&gt; <BR>&gt; &gt; hola daniel:<BR>&gt; &gt;<BR>&gt;=
 &gt; estuvimos implementando el tad diccionario, en private pusimos: un <B=
R>&gt; &gt; puntero a la raiz y una cantidad.(ordenariamos los nodos como u=
n <BR>&gt; &gt; arbol binario segun la clave).<BR>&gt; &gt; cada nodo tiene=
 un puntero nodo izquierdo. un puntero a nodo <BR>&gt; &gt; derecho, una cl=
ave y un valor.<BR>&gt; &gt;<BR>&gt; &gt; pero muchos metodos nos quedan re=
cursivos:<BR>&gt; &gt; ejemplo:<BR>&gt; &gt;<BR>&gt; &gt; bool diccionario:=
:contieneClave(clave k)const<BR>&gt; &gt; {<BR>&gt; &gt; if ( this-&gt;raiz=
=3D=3DNULL)<BR>&gt; &gt; {<BR>&gt; &gt; return false;<BR>&gt; &gt; }<BR>&gt=
; &gt; else if( this-&gt;raiz-&gt;clave=3D=3Dk)<BR>&gt; &gt; {<BR>&gt; &gt;=
 return true;<BR>&gt; &gt; }<BR>&gt; &gt; else if( this-&gt;raiz-&gt;clave&=
lt;k)<BR>&gt; &gt; {<BR>&gt; &gt; return (this-&gt;raiz-&gt;izquierdo).cont=
ieneClave(k);<BR>&gt; &gt; }<BR>&gt; &gt; else<BR>&gt; &gt; {<BR>&gt; &gt; =
return (this-&gt;raiz-&gt;derecho).contieneClave(k);<BR>&gt; &gt; }<BR>&gt;=
 &gt; }<BR>&gt; &gt;<BR>&gt; &gt;<BR>&gt; &gt; pero esto esta mal porq (thi=
s-&gt;raiz-&gt;izquierdo) es un puntero a <BR>&gt; &gt; nodo y le estamos a=
plicando un metodo para diccionarios.=BFcomo hacemos?<BR>&gt; &gt;<BR>&gt; =
&gt; pense en definir una variable auxiliar de tipo diccionario que <BR>&gt=
; &gt; tenga como raiz al primer nodo de la izquierda. pero nose que <BR>&g=
t; &gt; cantidad meterle( le meti cero y compilo pero no estariamos <BR>&gt=
; &gt; respetando el invariante de representacion)<BR>&gt; &gt;<BR>&gt; &gt=
; no se me ocurrio nada mas. pero casi todas las funciones nos <BR>&gt; &gt=
; quedaron de ese estilo.<BR>&gt; &gt; =BFhay manera de salvarlo o lo encar=
amos por otro lado?<BR>&gt; &gt;<BR>&gt; &gt; saludos<BR>&gt; &gt; gracias<=
BR>&gt; &gt; mateo<BR>&gt; &gt;<BR>&gt; &gt; &gt; From: dgorin@dc.uba.ar<BR=
>&gt; &gt; &gt; Date: Tue, 17 Jun 2008 20:26:53 -0300<BR>&gt; &gt; &gt; To:=
 flavia@bonomo.com.ar<BR>&gt; &gt; &gt; CC: ic-alu@dc.uba.ar<BR>&gt; &gt; &=
gt; Subject: Re: [ic-alu] clase del mi=E9rcoles y marcha<BR>&gt; &gt; &gt;<=
BR>&gt; &gt; &gt; Buenas<BR>&gt; &gt; &gt;<BR>&gt; &gt; &gt; Como creo que =
no se desprende del mail de Flavia, aclaro que tampoco<BR>&gt; &gt; &gt; va=
 a haber laboratorio ma=F1ana. Vamos a correr la entrega del TP para<BR>&gt=
; &gt; &gt; el mi=E9rcoles que viene.<BR>&gt; &gt; &gt;<BR>&gt; &gt; &gt; S=
aludos<BR>&gt; &gt; &gt; Daniel<BR>&gt; &gt; &gt;<BR>&gt; &gt; &gt; pd: Seg=
uimos respondiendo consultas por mail...<BR>&gt; &gt; &gt;<BR>&gt; &gt; &gt=
; On Jun 17, 2008, at 6:46 PM, Flavia Bonomo wrote:<BR>&gt; &gt; &gt;<BR>&g=
t; &gt; &gt; &gt; Hola chicos,<BR>&gt; &gt; &gt; &gt;<BR>&gt; &gt; &gt; &gt=
; Ma=F1ana miercoles a las 15hs es la movilizaci=F3n a la Plaza de Mayo<BR>=
&gt; &gt; &gt; &gt; llamada por varias organizaciones sociales.<BR>&gt; &gt=
; &gt; &gt;<BR>&gt; &gt; &gt; &gt; En particular, yo pienso ir a la marcha,=
 y por lo tanto<BR>&gt; &gt; &gt; &gt; no voy a dar clase de Introducci=F3n=
 ni de L=F3gica que<BR>&gt; &gt; &gt; &gt; caen a la misma hora.<BR>&gt; &g=
t; &gt; &gt;<BR>&gt; &gt; &gt; &gt; Para aquellos que quieran saber (m=E1s =
o menos) los motivos por los<BR>&gt; &gt; &gt; &gt; cuales voy a la marcha =
y/o adherir al texto, les paso un documento<BR>&gt; &gt; &gt; &gt; de un<BR=
>&gt; &gt; &gt; &gt; grupo<BR>&gt; &gt; &gt; &gt; independiente que llama a=
 la movilizaci=F3n, entre los que estamos<BR>&gt; &gt; &gt; &gt; varios doc=
entes, graduados y estudiantes de Exactas.<BR>&gt; &gt; &gt; &gt;<BR>&gt; &=
gt; &gt; &gt; saludos,<BR>&gt; &gt; &gt; &gt; flavia<BR>&gt; &gt; &gt; &gt;=
<BR>&gt; &gt; &gt; &gt; <BR>&gt; &gt; *************************************=
*********************************<BR>&gt; &gt; &gt; &gt; *<BR>&gt; &gt; &gt=
; &gt;<BR>&gt; &gt; &gt; &gt; Por qu=E9 vamos a la plaza<BR>&gt; &gt; &gt; =
&gt; (adhesiones a arte@centrocultural.coop)<BR>&gt; &gt; &gt; &gt;<BR>&gt;=
 &gt; &gt; &gt; Hoy (por ma=F1ana mi=E9rcoles 18 de junio) a las 13 nos <BR=
>&gt; &gt; concentramos en<BR>&gt; &gt; &gt; &gt; Avenida de Mayo y Per=FA,=
 en defensa de la democracia y en <BR>&gt; &gt; reclamo de<BR>&gt; &gt; &gt=
; &gt; mayor distribuci=F3n de la riqueza y participaci=F3n popular.<BR>&gt=
; &gt; &gt; &gt;<BR>&gt; &gt; &gt; &gt; Lo haremos desde nuestra propia ide=
ntidad y sin ahorrar <BR>&gt; &gt; cr=EDticas al<BR>&gt; &gt; &gt; &gt; Pod=
er Ejecutivo Nacional, pero en respaldo de la institucionalidad<BR>&gt; &gt=
; &gt; &gt; democr=E1tica y de las medidas progresivas que enfurecieron a u=
na <BR>&gt; &gt; nueva<BR>&gt; &gt; &gt; &gt; derecha que usa la ret=F3rica=
 del di=E1logo y el consenso y se <BR>&gt; &gt; envuelve en<BR>&gt; &gt; &g=
t; &gt; los s=EDmbolos nacionales mientras pretende mantener sus <BR>&gt; &=
gt; privilegios.<BR>&gt; &gt; &gt; &gt; Con lock-out patronal y desabasteci=
miento no hay vocaci=F3n de <BR>&gt; &gt; dialogo.<BR>&gt; &gt; &gt; &gt; E=
s imprescindible el levantamiento de las medidas de fuerza, y <BR>&gt; &gt;=
 que el<BR>&gt; &gt; &gt; &gt; gobierno haga una amplia convocatoria a todo=
s los sectores<BR>&gt; &gt; &gt; &gt; involucrados, para la discusi=F3n int=
egral de un nuevo modelo<BR>&gt; &gt; &gt; &gt; productivo.<BR>&gt; &gt; &g=
t; &gt;<BR>&gt; &gt; &gt; &gt; Somos miembros de organizaciones sindicales =
como la CTA, CTERA, la<BR>&gt; &gt; &gt; &gt; Uni=F3n Obrera Metal=FArgica,=
 CONADU; de movimientos como Tupac <BR>&gt; &gt; Amaru y<BR>&gt; &gt; &gt; =
&gt; Movimiento Nacional Patria Grande; de organismos de derechos <BR>&gt; =
&gt; humanos<BR>&gt; &gt; &gt; &gt; como el CELS, la Liga Argentina por los=
 Derechos del Hombre, las<BR>&gt; &gt; &gt; &gt; Madres de Plaza de Mayo-L=
=EDnea Fundadora, la Asamblea Permanente <BR>&gt; &gt; por<BR>&gt; &gt; &gt=
; &gt; los Derechos Humanos; de peque=F1os empresarios, como la Asamblea de=
<BR>&gt; &gt; &gt; &gt; PYMES y el Instituto Movilizador de Fondos Cooperat=
ivos; <BR>&gt; &gt; economistas<BR>&gt; &gt; &gt; &gt; del Plan F=E9nix; de=
canos y profesores universitarios, cient=EDficos e<BR>&gt; &gt; &gt; &gt; i=
nvestigadores; sacerdotes en opci=F3n por los pobres; dirigentes<BR>&gt; &g=
t; &gt; &gt; pol=EDticos que demostramos la posibilidad de construir altern=
ativas<BR>&gt; &gt; &gt; &gt; populares sin clientelas ni aparatos; intelec=
tuales y artistas<BR>&gt; &gt; &gt; &gt; integrantes del agrupamiento Carta=
 Abierta y ciudadanos sin <BR>&gt; &gt; militancia<BR>&gt; &gt; &gt; &gt; p=
artidaria ni institucional.<BR>&gt; &gt; &gt; &gt;<BR>&gt; &gt; &gt; &gt; N=
o formamos parte del gobierno. Objetamos la destrucci=F3n del <BR>&gt; &gt;=
 INDEC y<BR>&gt; &gt; &gt; &gt; la construcci=F3n del tren bala, la negativ=
a a reconocer la <BR>&gt; &gt; personer=EDa<BR>&gt; &gt; &gt; &gt; de la CT=
A y la alianza con sectores de la mal llamada burgues=EDa<BR>&gt; &gt; &gt;=
 &gt; nacional, que fue socia de los gobiernos neoliberales. <BR>&gt; &gt; =
Consideramos<BR>&gt; &gt; &gt; &gt; intolerable el mantenimiento de altos n=
iveles de hambre y <BR>&gt; &gt; exclusi=F3n en<BR>&gt; &gt; &gt; &gt; uno =
de los grandes pa=EDses productores de alimentos del mundo.<BR>&gt; &gt; &g=
t; &gt;<BR>&gt; &gt; &gt; &gt; Pero la restauraci=F3n conservadora en march=
a, con el impulso de un<BR>&gt; &gt; &gt; &gt; sector de la izquierda que i=
magina protagonizar una revoluci=F3n<BR>&gt; &gt; &gt; &gt; agraria, no cue=
stiona los defectos sino los aciertos del <BR>&gt; &gt; gobierno, al<BR>&gt=
; &gt; &gt; &gt; que intenta imponerle sus intereses econ=F3micos por encim=
a del <BR>&gt; &gt; inter=E9s<BR>&gt; &gt; &gt; &gt; general, sin reparar e=
n costos ni en m=E9todos. Cuestiona la<BR>&gt; &gt; &gt; &gt; reconstrucci=
=F3n de la autoridad del Estado luego del colapso de <BR>&gt; &gt; 2002,<BR=
>&gt; &gt; &gt; &gt; el saneamiento de la Corte Suprema de Justicia, el jui=
cio a los<BR>&gt; &gt; &gt; &gt; responsables del Estado terrorista, el dr=
=E1stico descenso de la<BR>&gt; &gt; &gt; &gt; desocupaci=F3n, la recuperac=
i=F3n del r=E9gimen jubilatorio estatal, el<BR>&gt; &gt; &gt; &gt; establec=
imiento de un haber para las personas mayores de 70 <BR>&gt; &gt; a=F1os qu=
e<BR>&gt; &gt; &gt; &gt; no ten=EDan ninguno, el aumento del presupuesto ed=
ucativo, la <BR>&gt; &gt; creaci=F3n<BR>&gt; &gt; &gt; &gt; de un ministeri=
o de ciencia y tecnolog=EDa, la pol=EDtica exterior<BR>&gt; &gt; &gt; &gt; =
independiente, en asociaci=F3n con los gobiernos democr=E1ticos de<BR>&gt; =
&gt; &gt; &gt; Sudam=E9rica. No busca un avance sino un salto atr=E1s.<BR>&=
gt; &gt; &gt; &gt;<BR>&gt; &gt; &gt; &gt; Contra toda evidencia se acusa de=
 autoritario y soberbio al primer<BR>&gt; &gt; &gt; &gt; gobierno que ha pr=
ohibido el uso de armas de fuego en el <BR>&gt; &gt; control de<BR>&gt; &gt=
; &gt; &gt; manifestaciones y se moteja de represi=F3n violenta al desalojo=
 con<BR>&gt; &gt; &gt; &gt; guantes de seda de la ruta del MERCOSUR, por la=
 que desde hace <BR>&gt; &gt; tres<BR>&gt; &gt; &gt; &gt; meses no se permi=
te el tr=E1nsito de mercader=EDas, obligando a tirar<BR>&gt; &gt; &gt; &gt;=
 millones de litros de leche y toneladas de frutas y verduras. <BR>&gt; &gt=
; De ese<BR>&gt; &gt; &gt; &gt; clima deslegitimador, parecido al que min=
=F3 la presidencia de <BR>&gt; &gt; Arturo<BR>&gt; &gt; &gt; &gt; Illia, pa=
rticipan en forma tan entusiasta como irreflexiva <BR>&gt; &gt; sectores de=
<BR>&gt; &gt; &gt; &gt; las clases medias urbanas influidos por la cobertur=
a <BR>&gt; &gt; tendenciosa de<BR>&gt; &gt; &gt; &gt; diarios y canales de =
televisi=F3n temerosos de que se democratice la<BR>&gt; &gt; &gt; &gt; comu=
nicaci=F3n de masas.<BR>&gt; &gt; &gt; &gt;<BR>&gt; &gt; &gt; &gt; De esta =
crisis, no menos grave porque se la niegue, s=F3lo se <BR>&gt; &gt; sale co=
n<BR>&gt; &gt; &gt; &gt; m=E1s democracia y m=E1s distribuci=F3n de la riqu=
eza. Para ello se <BR>&gt; &gt; impone<BR>&gt; &gt; &gt; &gt; una reforma i=
mpositiva integral, que grave a todos los sectores <BR>&gt; &gt; que en<BR>=
&gt; &gt; &gt; &gt; estos a=F1os han tenido beneficios extraordinarios, com=
o la <BR>&gt; &gt; especulaci=F3n<BR>&gt; &gt; &gt; &gt; financiera, la min=
er=EDa y la pesca.<BR>&gt; &gt; &gt; &gt;<BR>&gt; &gt; &gt; &gt; =C9sa es l=
a voz propia con la que hoy iremos a la Plaza de Mayo, en<BR>&gt; &gt; &gt;=
 &gt; defensa del valioso trayecto recorrido desde mayo de 2003 y en <BR>&g=
t; &gt; demanda<BR>&gt; &gt; &gt; &gt; de su profundizaci=F3n, con mayor ca=
lidad institucional y con la<BR>&gt; &gt; &gt; &gt; participaci=F3n popular=
.<BR>&gt; &gt; &gt; &gt;<BR>&gt; &gt; &gt; &gt;<BR>&gt; &gt; &gt; &gt; Jorg=
e Aliaga, Carolina Vera, Juan Pablo<BR>&gt; &gt; &gt; &gt; Paz, Alberto Kor=
nblihtt, Adri=E1n Paenza, Guillermo Dussel,<BR>&gt; &gt; &gt; &gt; Jose Ola=
be, Norberto Iusem, Esteban Hasson, Marcelo Frias, Roberto<BR>&gt; &gt; &gt=
; &gt; Etchenique, Julian Fernandez Bonder, Guillermo Duran, Vera Brudny,<B=
R>&gt; &gt; &gt; &gt; Flavia Bonomo, Ana Menendez, Pablo Paez, Ricardo Cabr=
era,<BR>&gt; &gt; &gt; &gt; Luciano Moffat, Leonardo Zayat, Dario Estrin, S=
ilvina<BR>&gt; &gt; &gt; &gt; Ponce Dawson, Pablo Groisman, Agustin Petroni=
, Eduardo Dvorkin, <BR>&gt; &gt; Diego<BR>&gt; &gt; &gt; &gt; Garbebersky, =
Ruth Rosenstein, Adali Pecci, Claudia Perez Leiros,<BR>&gt; &gt; &gt; &gt; =
Marcos Mobbili, Mariano Camilo Gonzalez Lebrero, Hugo Yasky, <BR>&gt; &gt; =
Mart=EDn<BR>&gt; &gt; &gt; &gt; Sabbatella, Horacio Verbitsky, Laura Conte,=
 Juan<BR>&gt; &gt; &gt; &gt; Gelman, Eduardo de la Serna, Abraham Gak, Carl=
os Heller, Horacio<BR>&gt; &gt; &gt; &gt; Gonz=E1lez,<BR>&gt; &gt; &gt; &gt=
; Nicol=E1s Casullo, Lilia Ferreyra,<BR>&gt; &gt; &gt; &gt; Ana Cacopardo, =
Victorio Paul=F3n, Stella Maldonado, Roberto <BR>&gt; &gt; Baradell,<BR>&gt=
; &gt; &gt; &gt; Carlos De Feo, Juan Carlos Junio, Juano Villafa=F1e, icent=
e <BR>&gt; &gt; Battista,<BR>&gt; &gt; &gt; &gt; Alejandro Dolina<BR>&gt; &=
gt; &gt; &gt;<BR>&gt; &gt; &gt; &gt;<BR>&gt; &gt; &gt; &gt;<BR>&gt; &gt; &g=
t; &gt; _______________________________________________<BR>&gt; &gt; &gt; &=
gt; ic-alu mailing list<BR>&gt; &gt; &gt; &gt; ic-alu@dc.uba.ar<BR>&gt; &gt=
; &gt; &gt; https://listas.dc.uba.ar/cgi-bin/mailman/listinfo/ic-alu<BR>&gt=
; &gt; &gt;<BR>&gt; &gt; &gt; _____________________________________________=
__<BR>&gt; &gt; &gt; ic-alu mailing list<BR>&gt; &gt; &gt; ic-alu@dc.uba.ar=
<BR>&gt; &gt; &gt; https://listas.dc.uba.ar/cgi-bin/mailman/listinfo/ic-alu=
<BR>&gt; &gt;<BR>&gt; &gt;<BR>&gt; &gt; =BFAburrido? Ingres=E1 ya y diverti=
te como nunca en MSN Juegos. MSN Juegos<BR>&gt; <BR><br /><hr />Descarg=E1 =
ya gratis y viv=ED la experiencia Windows Live. <a href=3D'http://www.descu=
brewindowslive.com/latam/index.html' target=3D'_new'>Descubre Windows Live<=
/a></body>
</html>=

--_15c8f27f-5517-440c-a29f-316f0490fc47_--

