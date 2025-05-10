#include <windows.h>
#include <GL/glut.h>
#include <math.h>

bool isDay = true; // Start with night scene
float timeOfDay = 0.0f; // Simulates time of day (0.0f to 1.0f)
float _move, _moveSn, _moveVh= 0.0f;


float speed = 0.1f;

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}


void init(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-29,34.02,-18.3,37.6); // window size
}


void Sky()
{

 //cloud
 glPushMatrix();
    glTranslatef(_move, 0, 0);
//1
 glColor3ub(209, 214, 217 );
  circle(1.467,1.467,-24.1455080938932, 24.6002742891383 );
  circle(2.2029,2.2029,-17.0229147924345, 26.5622803697287 );
circle(2.2,2.2,-19.5661664777232, 22.6906868798477 );
circle(2.767,2.767,-21.5743765417486, 25.9707633177559);
circle(1.954,1.954,-13.7168868561312, 25.4783367840555);
 circle(1.994,1.994,-16.8061260752998, 23.4188439712764 );


//2
  glColor3ub(215, 219, 221 );
 circle(1.718,1.718,-0.1301487379636, 33.3957464243702 );
 circle(2.121,2.121,3.3441412344733, 33.8599378810431 );
  circle(2.198,2.198,9.3885700327181, 32.1111991514306 );
   circle(1.647,1.647,2.066197297683, 31.573288917396 );
     circle(1.844,1.844,5.689, 35.112);
       circle(2.093,2.093,7.531633090539061, 34.11992696388235);
     circle(2.3329,2.3329,5.9176681895541, 31.0393029939829 );


//3
glColor3ub(208, 211, 212);
 circle(1.498,1.498,20.9802808635221, 27.2816525142225 );
 circle(1.420,1.420,23.1202839820433, 27.6135707479287 );
  circle(1.539,1.539,26.0047815156897, 24.6046644618383 );
   circle(1.834,1.834,23.2420139962841, 25.6658905200747);
     circle(1.711,1.711,25.8592093024629, 26.9440556696039);


 glPopMatrix();

}
void Building()
{
    //soil
    glBegin(GL_POLYGON);
glColor3ub(220, 118, 51 );

glVertex2f(-28.7820338304217, 3.105412246259); // x, y
glVertex2f(33.9614176135943, 3.0792266401748);
glVertex2f(34.0139961185554, -18.3222158676408); // x, y
glVertex2f(-29.1386344495777, -18.1429177553356); // x, y
glEnd();
//grass

glBegin(GL_POLYGON);
glColor3ub(76,153,0);

glVertex2f(-28.8776,10.635); // x, y
glVertex2f(-28.7820338304217, 3.105412246259);
glVertex2f(33.9614176135943, 3.0792266401748); // x, y
glVertex2f(34.0262,11.24111); // x, y
glEnd();

glBegin(GL_POLYGON);
glColor3ub(76,153,0);

glVertex2f(-28.8287496063216, -8.2756799505777); // x, y
glVertex2f(-28.739202989771815, -18.32221586764081);
glVertex2f(-9.0284411932231, -18.1758341571268); // x, y
glVertex2f(-7.2237813096269, -8.339982523679); // x, y
glEnd();

glBegin(GL_POLYGON);
glColor3ub(76,153,0);

glVertex2f(34.0139961185554, -18.3222158676408); // x, y
glVertex2f(8.8988650726904, -18.3542153140016);
glVertex2f(7.0750252584454, -8.1924374737759); // x, y
glVertex2f(33.8722270351569, -8.2756799505777); // x, y
glEnd();

//--
glBegin(GL_POLYGON);
glColor3ub(128,255,0);

glVertex2f(-26.5250208804506, -12.6602997976614);
glVertex2f(-28.1444144936158, -9.6668752399925);
glVertex2f(-25.9606867425294, -11.6052403224174);
glVertex2f(-25.9116142087971, -9.3479037707327);
glVertex2f(-24.9056272672855, -11.6297765892836);
glVertex2f(-24.1695392613013, -9.1025411020713);
glVertex2f(-24.1450029944352, -11.6543128561497);
glVertex2f(-22.4765368475378, -10.9672973838978);
glVertex2f(-23.9487128595061, -12.9056624663227);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(128,255,0);

glVertex2f(-20.925886150305068, -15.663442781031055);
glVertex2f(-22.3017496096348, -12.9571794836291);
glVertex2f(-20.104714845653028, -14.831977075209892);
glVertex2f(-20.6526082123976, -12.2554171869324);
glVertex2f(-19.232, -14.02512);
glVertex2f(-18.7146155416084, -12.1219546967903);
glVertex2f(-17.9205, -14.0542);
glVertex2f(-16.9332680399052, -12.6062983352807);
glVertex2f(-17.599942221767, -15.6238762110764);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(128,255,0);

glVertex2f(-15.2076785606284, -13.5039988272257);
glVertex2f(-17.2797361721857, -9.7416990931478);
glVertex2f(-14.6249314503735, -12.0959656597402);
glVertex2f(-14.6494677172396, -8.9798597677406);
glVertex2f(-13.471726907664944, -12.169574460338607);
glVertex2f(-12.7755112246176, -9.4212727530121);
glVertex2f(-12.2694498312242, -11.7279216567481);
glVertex2f(-10.2084034144685, -9.6178027062602);
glVertex2f(-12.2363470823552, -13.4065618317578);
glEnd();

//building
//back
glBegin(GL_POLYGON);
glColor3ub(131, 145, 146);
glVertex2f(-28.856,6.127); // x, y
glVertex2f(-28.9,16.304);
glVertex2f(-24.866,16.252);
glVertex2f(-24.838,6.133);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(119, 135, 137);
glVertex2f(0, 5); // x, y
glVertex2f(-0.9773,14.357);
glVertex2f(-0.9777567908562, 17.023319240034);
glVertex2f(2.4192572754295, 16.9740871521168);
glVertex2f(1.9028980737001, 5.7474103571167);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(131, 145, 146);
glVertex2f(16.985, 5.5799); // x, y
glVertex2f(16.9676602917065, 18.1662303341493);
glVertex2f(18.3351481019478, 18.8684538042732);
glVertex2f(18.3361094877212, 5.5666013657137);

glEnd();

glBegin(GL_POLYGON);
glColor3ub(153, 163, 164);
glVertex2f(18.3361094877212, 5.5666013657137); // x, y
glVertex2f(18.3351481019478, 18.8684538042732);
glVertex2f(21.7264723771982, 18.8263338722383);
glVertex2f(21.6399502514432, 5.8047539461154);

glEnd();


glBegin(GL_POLYGON);
glColor3ub(128, 139, 150);
glVertex2f(24.963, 4.657); // x, y
glVertex2f(24.8343088222622, 17.1647091626556);
glVertex2f(27.9928650299598, 17.1324789972709);
glVertex2f(28.0188038532819, 4.8614189221438);
glEnd();


glBegin(GL_POLYGON);
glColor3ub(64, 115, 200 );
glVertex2f(28.0188038532819, 4.8614189221438);
glVertex2f(27.9970626031542, 21.7275922022261); // x, y
glVertex2f(30.780293841229, 22.5474587684807);
glVertex2f(30.7537285476826, 5.7846766159324);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(98, 101, 103);
glVertex2f(30.7537285476826, 5.7846766159324);
glVertex2f(30.771,16.565);
glVertex2f(34.028, 16.534); // x, y
glVertex2f(34.0238,5.578);

glEnd();

//front

//building-1
glBegin(GL_POLYGON);
glColor3ub	(167, 167, 167 );

glVertex2f(-24.8351257400823, 5.069432058783); // x, y
glVertex2f(-24.871742950306, 18.4347137904304); // x, y
glVertex2f(-19.5560711066534, 18.4514010197798); // x, y
glVertex2f(-19.4873244984879, 5.0114391234269);
glVertex2f(-17.9081281089555, 5.1051186303263);
glVertex2f(-16.7689761688136, 16.2788395469941);
glVertex2f(-16.7374601718684, 17.7295616340422);
glVertex2f(-19.5560711066534, 18.4514010197798);
glEnd();


glBegin(GL_POLYGON);
glColor3ub(141, 146, 151 );
glVertex2f(-19.5560711066534, 18.4514010197798); // x, y
glVertex2f(-19.4873244984879, 5.0114391234269);
glVertex2f(-17.9081281089555, 5.1051186303263);
glVertex2f(-16.7689761688136, 16.2788395469941);
glVertex2f(-16.7374601718684, 17.7295616340422);
glVertex2f(-19.5560711066534, 18.4514010197798);

glEnd();

//building-1 Window
glBegin(GL_POLYGON);
glColor3ub(111, 157, 201 );
glVertex2f(-22.6462739472864, 6.6257763291905); // x, y
glVertex2f(-22.6462739472864, 17.392677297733);
glVertex2f(-20.2435371883083, 17.4202018972975);
glVertex2f(-20.2945916723445, 6.5707376779544);
glEnd();

glLineWidth(1);
glBegin(GL_LINES);
glColor3ub(212, 218, 224 );
glVertex2f(-22.178185, 17.39804);
glVertex2f(-22.152254,6.61424);
glEnd();
glBegin(GL_LINES);
glColor3ub(212, 218, 224 );
glVertex2f(-21.486407, 17.40696);
glVertex2f(-21.44039,6.59755);
glEnd();
glBegin(GL_LINES);
glColor3ub(212, 218, 224 );
glVertex2f(-20.848, 17.413);
glVertex2f(-20.849,6.584);
glEnd();

glBegin(GL_LINES);
glColor3ub(212, 218, 224 );
glVertex2f(-22.646, 16.168);
glVertex2f(-20.2494,16.1678);
glEnd();

glBegin(GL_LINES);
glColor3ub(212, 218, 224 );
glVertex2f(-22.646, 14.637);
glVertex2f(-20.2567,14.643);
glEnd();

glBegin(GL_LINES);
glColor3ub(212, 218, 224 );
glVertex2f(-22.646, 13.2914);
glVertex2f(-20.263,13.2913);
glEnd();

glBegin(GL_LINES);
glColor3ub(212, 218, 224 );
glVertex2f(-22.646, 11.9399);
glVertex2f(-20.269,12.0085);//
glEnd();

glBegin(GL_LINES);
glColor3ub(212, 218, 224 );
glVertex2f(-22.646, 10.494);
glVertex2f(-20.276,10.5189);
glEnd();

glBegin(GL_LINES);
glColor3ub(212, 218, 224 );
glVertex2f(-22.646, 9.20656);
glVertex2f(-20.2823,9.1809);
glEnd();
glBegin(GL_LINES);
glColor3ub(212, 218, 224 );
glVertex2f(-22.646, 7.92);
glVertex2f(-20.2883,7.9198);
glEnd();
//2

glBegin(GL_POLYGON);
glColor3ub	(202, 202, 202);

glVertex2f(-17.9081281089555, 5.1051186303263);
glVertex2f(-17.9119453126142, 16.2550403911946);
glVertex2f(-12.568,16.236); // x, y
glVertex2f(-12.5686034707175, 4.9852926819675);

glEnd();
//Window
glLineWidth(8);
glBegin(GL_LINES);
glColor3ub(111, 157, 201 );
glVertex2f(-16.4983000196467, 12.7987768590492);
glVertex2f(-16.4006096029966, 14.7525851920505);
glEnd();

glBegin(GL_LINES);
glColor3ub(111, 157, 201 );
glVertex2f(-14.5119282144288,14.7525851920505);
glVertex2f(-14.5770551588622,12.7987768590492);
glEnd();

glBegin(GL_LINES);
glColor3ub(111, 157, 201 );
glVertex2f(-16.4983000196467, 11.1054763037815);
glVertex2f(-16.4006096029966,9.2493583874304);
glEnd();

glBegin(GL_LINES);
glColor3ub(111, 157, 201 );
glVertex2f(-14.5119282144288, 11.1054763037815);
glVertex2f(-14.5770551588622,9.2493583874304);
glEnd();

glLineWidth(25);
glBegin(GL_LINES);
glColor3ub(111, 157, 201 );
glVertex2f(-15.2608880754126, 5.0486704714777);
glVertex2f(-15.2608880754126, 7.4258039432959);
glEnd();
//3

glBegin(GL_POLYGON);
glColor3ub	(192,192,192);

glVertex2f(-12.5686034707175, 4.9852926819675);
glVertex2f(-12.5674632831131, 21.2433256366004);
glVertex2f(-11.8964726182993, 20.6181409369307);
glVertex2f(-11.8494602141699, 4.9701031495415);
glEnd();

glBegin(GL_POLYGON);
glColor3ub	(192,192,192);
glVertex2f(-12.5674632831131, 21.2433256366004);
glVertex2f(-6.0153443190759, 21.2318948056612);
glVertex2f(-6.3458768774122065, 20.61814093693073);
glVertex2f(-11.8964726182993, 20.6181409369307);
glEnd();

glBegin(GL_POLYGON);
glColor3ub	(192,192,192);
glVertex2f(-6.0153443190759, 21.2318948056612);
glVertex2f(-6.3458768774122065, 20.61814093693073);
glVertex2f(-4.0065009891438, 19.2131647820359);
glVertex2f(-3.7401652470608, 19.8564020694232);
glEnd();




glBegin(GL_POLYGON);
glColor3ub(111, 148, 211);
glVertex2f(-11.8494602141699, 4.9701031495415); // x, y
glVertex2f(-11.8964726182993, 20.6181409369307);
glVertex2f(-6.3458768774122065, 20.61814093693073);
glVertex2f(-6.3992479903054, 14.007893204323);
glVertex2f(-8.8497,4.946);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(105, 140, 196);
glVertex2f(-6.3992479903054, 14.007893204323); // x, y
glVertex2f(-6.3458768774122065, 20.61814093693073);
glVertex2f(-4.0065009891438, 19.2131647820359);
glVertex2f(-4.0046,14.0809);
glEnd();

glLineWidth(1.5);
glBegin(GL_LINES);
glColor3ub(165, 189, 229);
glVertex2f(-10.832, 4.962);
glVertex2f(-10.865,20.618);
glEnd();

glBegin(GL_LINES);
glColor3ub(165, 189, 229);
glVertex2f(-9.627, 4.962);
glVertex2f(-9.77,20.6182);
glEnd();

glBegin(GL_LINES);
glColor3ub(165, 189, 229);
glVertex2f(-8.4226, 20.6182);
glVertex2f(-8.436,14.769);
glEnd();

glBegin(GL_LINES);
glColor3ub(165, 189, 229);
glVertex2f(-7.3205, 20.6182);
glVertex2f(-7.3778,14.7803);
glEnd();

//4
glBegin(GL_POLYGON);
glColor3ub(202, 202, 202);
glVertex2f(-8.8598171081112, 3.9536244934815); // x, y
glVertex2f(-8.783352569502, 14.7656878462577);
glVertex2f(-1.5555273352759, 14.8409776924476);
glVertex2f(-1.5104794687148, 3.9821714031679);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(170, 165, 165);
glVertex2f(-8.8598171081112, 3.9536244934815); // x, y
glVertex2f(-8.7897120655066, 14.0322850933657);
glVertex2f(-2.3067223672796, 14.0468624357563);
glVertex2f(-2.2577910767029, 4.001431985939);

glEnd();

glBegin(GL_POLYGON);
glColor3ub(144, 148, 151);
glVertex2f(-1.5104794687148, 3.9821714031679); // x, y
glVertex2f(-1.5555273352759, 14.8409776924476);
glVertex2f(-0.0177310764711, 13.5524570418726);
glVertex2f(0, 5);
glEnd();

//window
glBegin(GL_POLYGON);
glColor3ub(111, 157, 201 );
glVertex2f(-5.9984960707828, 6.7942693034158); // x, y
glVertex2f(-6, 13);
glVertex2f(-2.8565077335703, 13.0384739735722);
glVertex2f(-2.8239600877505, 6.8076609972184);
glEnd();

glLineWidth(1);
glBegin(GL_LINES);
glColor3ub(190, 204, 228);
glVertex2f(-5.175, 6.7978);
glVertex2f(-5.1467,13.009);
glEnd();

glBegin(GL_LINES);
glColor3ub(190, 204, 228);
glVertex2f(-5.175, 6.7978);
glVertex2f(-5.1467,13.009);
glEnd();

glBegin(GL_LINES);
glColor3ub(190, 204, 228);
glVertex2f(-4.3877, 6.8142);
glVertex2f(-4.4265,13.0193);
glEnd();

glBegin(GL_LINES);
glColor3ub(190, 204, 228);
glVertex2f(-3.576, 6.8045);
glVertex2f(-3.6143,13.0292);
glEnd();

glBegin(GL_LINES);
glColor3ub(190, 204, 228);
glVertex2f(-5.9997,11.866);
glVertex2f(-2.857,11.866);
glEnd();

glBegin(GL_LINES);
glColor3ub(190, 204, 228);
glVertex2f(-5.9994, 10.659);
glVertex2f(-2.844,10.653);
glEnd();

glBegin(GL_LINES);
glColor3ub(190, 204, 228);
glVertex2f(-5.9991, 9.3804);
glVertex2f(-2.837,9.388);
glEnd();

glBegin(GL_LINES);
glColor3ub(190, 204, 228);
glVertex2f(-5.999,8.126);
glVertex2f(-2.831,8.146);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(111, 157, 201 );
glVertex2f(-7.9687132750962, 11.2631649537235); // x, y
glVertex2f(-7.9933293190548, 13.1832163824937);
glVertex2f(-6.9840715167526, 13.1832163824937);
glVertex2f(-7.0058719430468, 11.2699881679551);
glEnd();

glBegin(GL_LINES);
glColor3ub(190, 204, 228);
glVertex2f(-7.982, 12.266);
glVertex2f(-6.995,12.263);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(111, 157, 201 );
glVertex2f(-7.9975565509171, 8.3955400292007); // x, y
glVertex2f(-8.0119287916109, 10.2208145973097);
glVertex2f(-7.0633609058219, 10.2208145973097);
glVertex2f(-7.0921053872094, 8.3811677885069);
glEnd();

glBegin(GL_LINES);
glColor3ub(190, 204, 228);
glVertex2f(-8.005, 9.276);
glVertex2f(-7.0777331465157, 9.2722467115208);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(111, 157, 201 );
glVertex2f(-7.9933293190548, 5.626090887206); // x, y
glVertex2f(-7.9933293190548, 7.2999818763903);
glVertex2f(-7.1071517365455, 7.2753658324317);
glVertex2f(-7.0825356925869, 5.626090887206);
glEnd();

glBegin(GL_LINES);
glColor3ub(190, 204, 228);
glVertex2f(-7.094,6.413);
glVertex2f(-7.993, 6.413);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(146, 139, 139);
glVertex2f(-6.418, 3.971); // x, y
glVertex2f(-6.4309823152959, 5.8229089450155);
glVertex2f(-3.0535057522595, 5.8085367043217);
glVertex2f(-3.0417, 3.9958);
glEnd();

//5
glBegin(GL_POLYGON);
glColor3ub(40, 116, 166);
glVertex2f(1.9028980737001, 5.7474103571167); // x, y
glVertex2f(1.9028980737001, 13.1019323980211);
glVertex2f(3.577098213093, 15.0153039858986);
glVertex2f(3.577098213093, 4.0732102177239);

glEnd();

glBegin(GL_POLYGON);
glColor3ub(52, 152, 219 );
glVertex2f(3.577098213093, 4.0732102177239); // x, y
glVertex2f(3.577098213093, 15.0153039858986);
glVertex2f(9.9968249892084, 15.0177904640282);
glVertex2f(10, 4);

glEnd();


glLineWidth(4.5);

glBegin(GL_LINES);
glColor3ub(40, 116, 166);
glVertex2f(3.5771,14.0014);
glVertex2f(9.9972,13.999999);
glEnd();

glBegin(GL_LINES);
glColor3ub(40, 116, 166);
glVertex2f(3.5771,12.7991);
glVertex2f(9.9975,12.819);
glEnd();

glBegin(GL_LINES);
glColor3ub(40, 116, 166);
glVertex2f(3.5771,11.593);
glVertex2f(9.9978,11.6197);
glEnd();

glBegin(GL_LINES);
glColor3ub(40, 116, 166);
glVertex2f(3.5771,10.4755);
glVertex2f(9.9982,10.421);
glEnd();

glBegin(GL_LINES);
glColor3ub(40, 116, 166);
glVertex2f(3.5771,9.2769);
glVertex2f(9.9985,9.2496);
glEnd();

glBegin(GL_LINES);
glColor3ub(40, 116, 166);
glVertex2f(3.5771,8.0238);
glVertex2f(10,8);
glEnd();

glBegin(GL_LINES);
glColor3ub(40, 116, 166);
glVertex2f(3.5771,6.825);
glVertex2f(10,6.7979);
glEnd();

glBegin(GL_LINES);
glColor3ub(40, 116, 166);
glVertex2f(3.5771,5.681);
glVertex2f(10,5.6265);
glEnd();


glBegin(GL_LINES);
glColor3ub(153, 187, 209  );
glVertex2f(4.7502,15.0158);
glVertex2f(4.7618,4.0597);
glEnd();

//6
glBegin(GL_POLYGON);
glColor3ub(173, 185, 193 );
glVertex2f(9.9997, 5.0107); // x, y
glVertex2f(9.9975, 12.617);
glVertex2f(14.5926973350555, 12.5716003444644);
glVertex2f(14.6297608217156, 5.0477125524729);
glEnd();

glLineWidth(5);
glBegin(GL_LINES);
glColor3ub(110, 142, 194 );
glVertex2f(9.9975, 12.617);
glVertex2f(14.5926973350555, 12.5716003444644);
glVertex2f(14.3926973350555, 12.5716003444644);
glVertex2f(14.4297608217156, 5.0477125524729);
glEnd();

glLineWidth(5);
glBegin(GL_LINES);
glColor3ub(127, 140, 141 );
glVertex2f(9.998,10.611);
glVertex2f(14.178, 10.611);
glEnd();

glBegin(GL_LINES);
glColor3ub(127, 140, 141);
glVertex2f(9.9986,9);
glVertex2f(14.187, 8.9996);
glEnd();

glBegin(GL_LINES);
glColor3ub(127, 140, 141 );
glVertex2f(9.998,7.635);
glVertex2f(14.195, 7.617);
glEnd();

glBegin(GL_LINES);
glColor3ub(127, 140, 141 );
glVertex2f(9.993,6.216);
glVertex2f(14.202, 6.2337);
glEnd();

//7
glBegin(GL_POLYGON);
glColor3ub(166, 173, 184);
glVertex2f(14.627,5.603); // x, y
glVertex2f(14.596,11.978);
glVertex2f(18.3361094877212, 11.9415210712435);
glVertex2f(18.3361094877212, 5.5666013657137);
glEnd();
//window
glLineWidth(5);
glBegin(GL_LINES);
glColor3ub(127, 140, 141 );
glVertex2f(15.217050770283, 11.1624248837492);
glVertex2f(17.6873047793003, 11.1749642442011);
glEnd();

glBegin(GL_LINES);
glColor3ub(127, 140, 141 );
glVertex2f(15.2045114098312, 9.9210281990147);
glVertex2f(17.6747654188485, 9.9084888385628);
glEnd();

glBegin(GL_LINES);
glColor3ub(127, 140, 141 );
glVertex2f(15.2238904214386, 8.6887510491542);
glVertex2f(17.6519665816633, 8.6773516305616);
glEnd();

glBegin(GL_LINES);
glColor3ub(127, 140, 141 );
glVertex2f(15.2193306540016, 7.4838325039159);
glVertex2f(17.677045302567, 7.4838325039159);
glEnd();
glLineWidth(7);
glBegin(GL_LINES);
glColor3ub(127, 140, 141 );
glVertex2f(15.6205901884612, 5.9916486101441);
glVertex2f(17.3635612912704, 6.0167273310478);
glEnd();


//8
glBegin(GL_POLYGON);
glColor3ub(149, 165, 166);
glVertex2f(21.665,9.519); // x, y
glVertex2f(21.6158155471538, 4.6529922301919);
glVertex2f(26.8325790761117, 4.659404993404);
glVertex2f(26.821,8.5);
glEnd();
glBegin(GL_POLYGON);
glColor3ub(171, 178, 185);
glVertex2f(21.3287229876583, 8.4262087264192); // x, y
glVertex2f(21.3287229876583, 13.1017161239183);
glVertex2f(27.357666737065, 13.1017161239183);
glVertex2f(27.357666737065, 8.3851955036341);
glEnd();
//window
glLineWidth(7);
glBegin(GL_LINES);
glColor3ub(106, 146, 212 );
glVertex2f(22, 12);
glVertex2f(26.6414620293132, 11.9990119116728);
glEnd();

glBegin(GL_LINES);
glColor3ub(106, 146, 212);
glVertex2f(22, 10);
glVertex2f(26.6211322420508, 10.0066927599539);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(94, 120, 162);
glVertex2f(22.4063045082608, 6.038986438034); // x, y
glVertex2f(22.4063045082608, 7.1766482974582);
glVertex2f(23.970589564969, 7.1360175167645);
glVertex2f(24, 6);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(94, 120, 162);
glVertex2f(24.963,4.657); // x, y
glVertex2f(24.9788998155303, 7.0727723745116);
glVertex2f(26.1682832762977, 7.0727723745116);
glVertex2f(26.165, 4.659);
glEnd();

//tower
glBegin(GL_POLYGON);
glColor3ub(108, 113, 120);
glVertex2f(9.998,12.617); // x, y
glVertex2f(9.998, 14);
glVertex2f(13.1101578686532, 14);
glVertex2f(13.1102, 12.586);
glEnd();

glLineWidth(3);
glBegin(GL_LINES);
glColor3ub(146, 155, 170 );
glVertex2f(11.053, 14.006);
glVertex2f(11.0566553573909, 18.8670657796475);
glVertex2f(11.0566553573909, 18.8670657796475);
glVertex2f(12.3417615151579, 18.9241816088816);
glVertex2f(12.3417615151579, 18.9241816088816);
glVertex2f(12.4304, 14.0134);

glVertex2f(12.4304, 14.0134);
glVertex2f(11.05444, 15.911);

glVertex2f(11.05444, 15.911);
glVertex2f(12.3417615151579, 18.9241816088816);

glVertex2f(11.0566553573909, 18.8670657796475);
glVertex2f(12.398, 15.804);

glVertex2f(12.398, 15.804);
glVertex2f(11.053, 14.006);
glEnd();

}
void tree()
{
   // circle(1.9515,28.2938095872804,26.1528105770382,231, 76, 60 );

}
void streat()
{

//road
glBegin(GL_POLYGON);
glColor3ub(98, 101, 103);

glVertex2f(-28.83666, 2.045115); // x, y
glVertex2f(-28.7395590278842, -5.064819126832); // x, y
glVertex2f(33.8722270351569, -5.1540097052694); // x, y
glVertex2f(34.0223,1.7578); // x, y

glEnd();

glBegin(GL_POLYGON);
glColor3ub(98, 101, 103);
glVertex2f(-4, -5); // x, y
glVertex2f(-5.9959615263522, -18.1758341571268); // x, y
glVertex2f(5.4204325136325, -18.3542153140016); // x, y
glVertex2f(3.5822593624801, -5.020556233543);
glEnd();

glLineWidth(5);
//lft
glBegin(GL_LINES);
glColor3ub(209, 227, 229);
glVertex2f(-8.5, -3.477148761574);
glVertex2f(-3.6667453562726, -3.5369307482399);
glEnd();

glBegin(GL_LINES);
glColor3ub(209, 227, 229);
glVertex2f(-8.329740316207, -1.8630351215968);
glVertex2f(-3.4276174096093, -1.803253134931);
glEnd();
glBegin(GL_LINES);
glColor3ub(209, 227, 229);
glVertex2f(-8.246210394182, -0.4313404537397);
glVertex2f(-3.2710441254423, -0.3848435727235);
glEnd();
glBegin(GL_LINES);
glColor3ub(209, 227, 229);
glVertex2f(-7.9112664095462, 1.1260642116945);
glVertex2f(-3.0689254896143, 1.2456281850261);
glEnd();

//rgt
glBegin(GL_LINES);
glColor3ub(209, 227, 229);
glVertex2f(3.2679650969632, -3.5369307482399);
glVertex2f(7.2934671324857, -3.5161446775103);
glEnd();

glBegin(GL_LINES);
glColor3ub(209, 227, 229);
glVertex2f(3.0886191369657, -2.1021630682601);
glVertex2f(6.9744482702444, -2.1021630682601);
glEnd();
glBegin(GL_LINES);
glColor3ub(209, 227, 229);
glVertex2f(2.5879516134379, -0.404432802011);
glVertex2f(6.6863038397053, -0.404432802011);
glEnd();
glBegin(GL_LINES);
glColor3ub(209, 227, 229);
glVertex2f(2.1918893369783, 1.1260642116945);
glVertex2f(6.4965653107115, 1.1134754299399);
glEnd();

//bottom
glBegin(GL_LINES);
glColor3ub(209, 227, 229);
glVertex2f(-2.6504515829536, -5.9282102148729);
glVertex2f(-3.188489462946, -8.9173095481641);
glEnd();

glBegin(GL_LINES);
glColor3ub(209, 227, 229);
glVertex2f(-0.9167739696446, -6.0477741882045);
glVertex2f(-0.9167739696446, -9.0368735214957);
glEnd();
glBegin(GL_LINES);
glColor3ub(209, 227, 229);
glVertex2f(0.936467616996, -5.9879922015387);
glVertex2f(1.1755955636593, -9.0368735214957);
glEnd();

glBegin(GL_LINES);
glColor3ub(209, 227, 229);
glVertex2f(2.4907992703075, -5.9282102148729);
glVertex2f(2.9690551636341, -9.0368735214957);
glEnd();


}
void TraficLight()
{
    //traffic light
glBegin(GL_POLYGON);
glColor3ub(66, 73, 73);
glVertex2f(-6.3396909506539, -6.0763343491403); // x, y
glVertex2f(-5.6129485121857, -6.1188248676932); // x, y
glVertex2f(-5.7521436032499, 0.7365333672186); // x, y
glVertex2f(-6.3396909506539, 0.7822974139038);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(-6.9307094174408, 0.7596556992257); // x, y
glVertex2f(-6.9297066291613, 5.8059553991688); // x, y
glVertex2f(-5.0742214605723, 5.816438366223); // x, y
glVertex2f(-5.0665558186934, 0.7596556992257);
glEnd();

glColor3ub(0, 128, 0);
 circle(0.633,0.633,-6.0176545935645, 1.6727105231019 );
 glColor3ub(255, 255, 0);
  circle(0.639,0.639,-5.9986326180671, 3.1754465873982);
  glColor3ub(255, 0, 0 );
   circle(0.675,0.675,-5.9796106425696, 4.8684024066688);
}

void Car()
{//1
glPushMatrix();
glTranslatef(-_moveVh, 0, 0);

glBegin(GL_POLYGON);

glColor3ub(222, 100, 73);
glVertex2f(-24.8174334770733, -0.5016943190254); // x, y
glVertex2f(-24.8174334770733, 1.4102102093231); // x, y
glVertex2f(-22.3592705120537, 2.112542485043); // x, y
glVertex2f(-21.1106797996628, 3.7903362548182);

glVertex2f(-17.0137415246301, 3.8293547145804);
glVertex2f(-15.6480954329526, 2.307634783854);
glVertex2f(-13.8922647436528, 1.4102102093231);
glVertex2f(-13.8142278241284, -0.5407127787877);

glEnd();

//window
glBegin(GL_POLYGON);
glColor3ub(52, 152, 219);
glVertex2f(-22.1089964045831, 1.844984690077); // x, y
glVertex2f(-20.9906453152868, 3.4233558481465); // x, y
glVertex2f(-20.5652257906169, 3.4233558481465); // x, y
glVertex2f(-20.5276887737342, 1.8217764611537);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(52, 152, 219);
glVertex2f(-19.9771458594554, 1.8092641221929); // x, y
glVertex2f(-19.9771458594554, 3.4108435091856); // x, y
glVertex2f(-18.7259119633673, 3.4233558481465); // x, y
glVertex2f(-18.7259119633673, 1.8217764611537);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(52, 152, 219);
glVertex2f(-18.237930743893, 1.8217764611537); // x, y
glVertex2f(-18.2629554218147, 3.4358681871074); // x, y
glVertex2f(-17.2244312880616, 3.4358681871074); // x, y
glVertex2f(-15.8992029233319, 1.8607856913016);
glEnd();

glColor3ub(0, 0, 0 );
circle(1.095,1.095,-21.843, 0);
circle(1.143,1.143,-16.8375213364975, -0.0669982111714);
glPopMatrix();

//2 bus
glPushMatrix();
glTranslatef(_moveVh, 0, 0);


glBegin(GL_POLYGON);
glColor3ub(243, 156, 18);
glVertex2f(17.2241734730589, -3.7843946501525); // x, y
glVertex2f(17.2328770298688, 0.8197462935303); // x, y
glVertex2f(28.367003903015, 0.7841658261294); // x, y
glVertex2f(29.1788386914833, -1.3170536263766);
glVertex2f(29.2106753498546, -3.7525579917812);


glEnd();

//window
glBegin(GL_POLYGON);
glColor3ub(52, 152, 219);
glVertex2f(18.179877720634, -1.183525833036); // x, y
glVertex2f(18.1773865785816, 0.2229523190716); // x, y
glVertex2f(24.4065668135279, 0.1860204204454); // x, y
glVertex2f(24.4070263951181, -1.1765094782942);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(52, 152, 219);
glVertex2f(27.218333475126, -1.2516284278554); // x, y
glVertex2f(27.2015497338463, 0.2924757698786); // x, y
glVertex2f(28.1214757346667, 0.3102682079055); // x, y
glVertex2f(28.8105808942187, -1.2195452463);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(52, 152, 219);
glVertex2f(24.943024081587, -3.5124205378117); // x, y
glVertex2f(24.943024081587, -0.4004864991653); // x, y
glVertex2f(26.5652024634347, -0.4004864991653); // x, y
glVertex2f(26.5817553040658, -3.5124205378117);
glEnd();

glColor3ub(0, 0, 0);
circle(0.9,0.9,19.1768907636814, -3.4660280664395 );
circle(0.9,0.9,27.7426536069415, -3.4314812853358 );

glPopMatrix();
//aeroplane
glPushMatrix();
glTranslatef(-_moveVh, 0, 0);
glBegin(GL_POLYGON);
glColor3ub(255, 255, 255);
glVertex2f(-3.0584031837309, 24.7304057138761); // x, y
glVertex2f(-3.359886609117, 25.930256584805); // x, y
glVertex2f(-1.6249848641631, 26.6049405967315); // x, y
glVertex2f(-0.6129588462733, 28.3880340568229);
glVertex2f(10.9312973613196, 27.0396416745009);
glVertex2f(12.9943287009332, 24.6900782043855);

glEnd();

glBegin(GL_POLYGON);
glColor3ub(255, 255, 255);
glVertex2f(10.9312973613196, 27.0396416745009);
glVertex2f(11.9650788046425, 29.3036766444375);
glVertex2f(14.0841905542598, 29.2572303939608);
glVertex2f(12.9943287009332, 24.6900782043855);

glEnd();

//lft
glBegin(GL_POLYGON);
glColor3ub(169, 204, 227);
glVertex2f(3.3387617950106, 25.2073808577409);
glVertex2f(8.6398504601476, 22.7977951008605);
glVertex2f(9.5884623443718, 23.4880170887592);
glVertex2f(7.0605315364184, 25.3747718730884);

glEnd();

//rgt
glBegin(GL_POLYGON);
glColor3ub(169, 204, 227);
glVertex2f(2.5685833837703, 28.0080973561926);
glVertex2f(4.3904357155548, 27.7854265156412);
glVertex2f(4.8999559929953, 29.8056830948863);
glVertex2f(4, 30);

glEnd();
//window
glBegin(GL_POLYGON);
glColor3ub(36, 113, 163);
glVertex2f(-1.135849690858, 26.4898870797056);
glVertex2f(0.008642280568, 26.2173827930771);
glVertex2f(1.2325583404618, 26.3886730612731);
glVertex2f(1.4349863773267, 27.7044553008952);
glVertex2f(-0.3868659544577, 27.8866405340736);
glEnd();

glLineWidth(7);
glBegin(GL_LINES);
glColor3ub(36, 113, 163);
glVertex2f(3.7393408857222, 27.0396416745009);
glVertex2f(5.2006547512818, 26.8677223961998);
glEnd();

glBegin(GL_LINES);
glColor3ub(36, 113, 163);
glVertex2f(5.8084081891298, 26.7500143561082);
glVertex2f(7.3619169146374, 26.6020611441551);
glEnd();

glBegin(GL_LINES);
glColor3ub(36, 113, 163);
glVertex2f(8.1519356954513, 26.5238838395975);
glVertex2f(9.8327355542542, 26.4245172898114);
glEnd();

//door
glLineWidth(7);
glBegin(GL_LINES);
glColor3ub(36, 113, 163);
glVertex2f(2.1310112375498, 24.8619974826866);
glVertex2f(2.1596644506, 27.0109884614507);
glEnd();
glPopMatrix();
}

void renderNightScene() {

    //sky
glBegin(GL_POLYGON);
glColor3ub(0,0,51);
glVertex2f(-28.8776,10.635); // x, y
glVertex2f(34.0262,11.24111);
glVertex2f(34.0371,37.5727); // x, y
glVertex2f(-29.0067,37.63122); // x, y
glEnd();

//moon
 glPushMatrix();
  //  glTranslatef(0, _moveSn, 0);
 glColor3ub(245, 245, 245);
 circle(2.478,2.478,-14.0011976092072, 30.0932859415109 );
   glPopMatrix();

   // Draw some stars
    glColor3f(1.0f, 1.0f, 1.0f); // White for stars
    glBegin(GL_POINTS);
    glVertex2f(-26.1112207475622, 34.8727610669835);
    glVertex2f(-3.8709732958442, 33.2794299062635);
    glVertex2f(3.8301273143029, 26.9724940617466);
    glVertex2f(7.6806776193765, 22.5908333697665);
    glVertex2f(16.5767766000636, 24.1841645304865);
    glVertex2f(-20.468135729641, 31.6598341079691);
    glVertex2f(-6.2915626508174, 26.4868331340622);
    glVertex2f(20.6928820985906, 32.6155419226301);
    glVertex2f(9.6270808311687, 36.2756409879981);
    glVertex2f(30.1221775390853, 33.1068230431333);
    glEnd();



    Sky();
Building();
streat();
tree();
Car();
TraficLight();
  glFlush();
}

void renderDayScene()
{

    //sky
glBegin(GL_POLYGON);
glColor3ub(0,206,209);
glVertex2f(-28.8776,10.635); // x, y
glVertex2f(34.0262,11.24111);
glVertex2f(34.0371,37.5727); // x, y
glVertex2f(-29.0067,37.63122); // x, y
glEnd();

//sun
 glPushMatrix();
glTranslatef(0, _moveSn, 0);
 glColor3ub(245, 176, 65);
 circle(2.478,2.478,-14.0011976092072, 30.0932859415109 );
   glPopMatrix();


    Sky();
Building();
streat();
tree();
Car();
TraficLight();
  glFlush();
}

// Timer callback to transition from night to day
void timer(int value) {
    // Simulate the passage of time
    timeOfDay += 0.01f;
    if (timeOfDay >= 3.0f) {
        isDay = false; // Change to day after "sunrise"
    }

    // Redraw the scene based on the time of day
    if (isDay) {
        renderDayScene();
    } else {
        renderNightScene();
    }

    // Keep updating every 100 ms
    glutTimerFunc(10, timer, 0);
}

void updateSPD(int value)
{

    if (_moveVh > 40)
        _moveVh = -30;
         _moveVh += speed;//vehical

glutPostRedisplay();
glutTimerFunc(100, updateSPD, 0);
}

void display() {
//glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque

glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

 if (isDay) {
        renderDayScene(); // Render the day scene
    } else {
        renderNightScene(); // Render the night scene
    }

    if (_moveSn < 35)
      _moveSn += .001;//sun


 _move += .005;//cloud
    if (_move > 50)
        _move = -28;


    glutPostRedisplay();


    glFlush();
    glutSwapBuffers();


}
/* Main function: GLUT runs as a console application starting at main() */

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{	speed += 0.2f;
			}
if (button == GLUT_RIGHT_BUTTON)
	{speed -= 0.2f;   }
glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
case 'a':
    speed = 0.0f;
    break;
case 'w':
    speed = 0.1f;
    break;
glutPostRedisplay();
	}}


int main(int argc, char** argv) {
glutInit(&argc, argv); // Initialize GLUT
//glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
//glutInitWindowSize(320, 320); // Set the window's initial width & height
//glutDisplayFunc(display); // Register display callback handler for window re-paint
//gluOrtho2D(-30,35,-20,40);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(150, 0);
    glutCreateWindow("City Scenario");
    init();
    glutDisplayFunc(display);
     glutTimerFunc(100, timer, 0);
      glutTimerFunc(100, updateSPD, 0);
       glutKeyboardFunc(handleKeypress);
      glutMouseFunc(handleMouse);
glutMainLoop(); // Enter the event-processing loop

return 0;
}


