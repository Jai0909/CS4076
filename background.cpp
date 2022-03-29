#include "background.h"

//constructor that sets blank window and creates rooms
Background::Background(Zork* zork1){
    this->zork1 = zork1;
    player=zork1->play();
    inventoryContString = "";
    setRoomExits(zork1->currentRoom);
    setSceneRect(0,0,1000,500);
    createCave();
    createMapGUI();
    createTextBox();
    addText();
    addToScene();
}

Background::~Background()
{
    clearBackground();
    player=nullptr;
    zork1=nullptr;
    delete cave;
    delete smallEditor;
    delete RoomA;
    delete RoomB;
    delete RoomC;
    delete RoomD;
    delete RoomE;
    delete RoomF;
    delete RoomG;
    delete RoomH;
    delete RoomI;
    delete RoomJ;
}

//Sets a new scne when you move rooms
void Background::setScene(const string direction)
{
    nextRoom = zork1->currentRoom->nextRoom(direction);
    if(nextRoom->getCanEnter()==true){
        clearBackground();

        nextRoom = zork1->currentRoom->nextRoom(direction);
        zork1->currentRoom=nextRoom;

        setRoomExits(zork1->currentRoom);
        addToScene();
        createMapGUI();
        addText();
    }
}

void Background::refreshScene(){
    clearBackground();
    setRoomExits(zork1->currentRoom);
    addToScene();
    createMapGUI();
}


//creates buttons depending on room exits
void Background::setRoomExits(Room * r){
    zork1->currentRoom = r;

    vector<string> listOfExits= zork1->currentRoom->exitString();
    int i =0;
    while(i<listOfExits.size())
    {
        if(listOfExits[i]=="north"){
            button1= new QPushButton();
            button1->move(450,25);
            button1->raise();
            button1->setText("North");
            delB1=1;
            this->addWidget(button1);

            connect(button1,SIGNAL(released()),this, SLOT(on_button1_clicked()));
        }
        else if(listOfExits[i]=="south"){
            button2= new QPushButton();
            button2->move(450,410);
            button2->setText("South");
            button2->raise();
            delB2=1;
            connect(button2,SIGNAL(released()),this, SLOT(on_button2_clicked()));
            this->addWidget(button2);
        }
        else if(listOfExits.at(i)=="east"){
            button3= new QPushButton();
            button3->move(750,200);
            button3->setText("East");
            button3->raise();
            delB3=1;
            connect(button3,SIGNAL(released()),this, SLOT(on_button3_clicked()));
            this->addWidget(button3);
        }
        else if(listOfExits.at(i)=="west"){
            button4= new QPushButton();
            button4->move(175,200);
            button4->setText("West");
            button4->raise();
            delB4=1;
            this->addWidget(button4);
            connect(button4,SIGNAL(released()),this, SLOT(on_button4_clicked()));
        }
    i++;
    }

}
void Background::createCave(){
    cave= new QGraphicsPixmapItem();
    cave->setPos(50,0);
    cave->setPixmap(QPixmap(":/Images/cave.jpg"));
    cave->setZValue(-1);
}

void Background:: createTextBox(){
    smallEditor = new QTextEdit;
    smallEditor->move(250,450);
    smallEditor->setReadOnly(true);
    this->addWidget(smallEditor);
}

void Background::createMapGUI()
{

    RoomA= new QGraphicsRectItem();
    RoomB= new QGraphicsRectItem();
    RoomC= new QGraphicsRectItem();
    RoomD= new QGraphicsRectItem();
    RoomE= new QGraphicsRectItem();
    RoomF= new QGraphicsRectItem();
    RoomG= new QGraphicsRectItem();
    RoomH= new QGraphicsRectItem();
    RoomI= new QGraphicsRectItem();
    RoomJ= new QGraphicsRectItem();

    RoomA->setRect(10,10,10,10);
    this->addItem(RoomA);

    RoomB->setRect(20,10,10,10);
    this->addItem(RoomB);

    RoomC->setRect(0,10,10,10);
    this->addItem(RoomC);

    RoomD->setRect(10,20,10,10);
    this->addItem(RoomD);

    RoomE->setRect(20,20,10,10);
    this->addItem(RoomE);

    RoomF->setRect(10,0,10,10);
    this->addItem(RoomF);

    RoomG->setRect(20,0,10,10);
    this->addItem(RoomG);

    RoomH->setRect(0,0,10,10);
    RoomH->setZValue(5);
    this->addItem(RoomH);

    RoomI->setRect(0,20,10,10);
    this->addItem(RoomI);

    RoomJ->setRect(0,30,10,10);
    this->addItem(RoomJ);

    if(zork1->currentRoom->getDescription()=="a")
        RoomA->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="b")
        RoomB->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="c")
        RoomC->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="d")
        RoomD->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="e")
        RoomE->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="f")
        RoomF->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="g")
        RoomG->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="h")
        RoomH->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="i")
        RoomI->setBrush(Qt::green);
    else if(zork1->currentRoom->getDescription()=="j")
        RoomJ->setBrush(Qt::green);
}

void Background:: addText(){
     string x="You are in Room "+zork1->currentRoom->getDescription()+ " and you have health of: "+ to_string(zork1->player->getHealth());
     smallEditor->setPlainText(QString::fromStdString(x));
}

//adds ghost and rectangle to scene
void Background::addToScene(){
    if(zork1->currentRoom->ghostInRoom()){
        zork1->vghost->setVisible(true);
        zork1->vghost->setFocus();
        timer = new MyTimer(zork1->vghost, player, zork1->currentRoom);
        this->addItem(zork1->vghost);
    }
    else if(zork1->currentRoom->vampireInRoom()){
        zork1->vvampire->setVisible(true);
        zork1->vvampire->setFocus();
        timer = new MyTimer(zork1->vvampire, player, zork1->currentRoom);
        this->addItem(zork1->vvampire);
    }
    else if(zork1->currentRoom->zombieInRoom()){
        zork1->vzombie->setVisible(true);
        zork1->vzombie->setFocus();
        timer = new MyTimer(zork1->vzombie, player, zork1->currentRoom);
        this->addItem(zork1->vzombie);
    }
    else if(zork1->currentRoom->mummyInRoom()){
        zork1->vmummy->setVisible(true);
        zork1->vmummy->setFocus();
        timer = new MyTimer(zork1->vmummy, player, zork1->currentRoom);
        this->addItem(zork1->vmummy);
    }
    else if(zork1->currentRoom->dragonInRoom()){
        zork1->vdragon->setVisible(true);
        zork1->vdragon->setFocus();
        timer = new MyTimer(zork1->vdragon, player, zork1->currentRoom);
        this->addItem(zork1->vdragon);
    }
    else if(zork1->currentRoom->alienInRoom()){
        zork1->valien->setVisible(true);
        zork1->valien->setFocus();
        timer = new MyTimer(zork1->valien, player, zork1->currentRoom);
        this->addItem(zork1->valien);
    }
    else if(zork1->currentRoom->pirateInRoom()){
        zork1->vpirate->setVisible(true);
        zork1->vpirate->setFocus();
        timer = new MyTimer(zork1->vpirate, player, zork1->currentRoom);
        this->addItem(zork1->vpirate);
    }
    this->addItem(cave);

}


void Background::on_button1_clicked()
{
    setScene("north");
}

void Background::on_button2_clicked()
{
    setScene("south");
}
void Background::on_button3_clicked()
{
    setScene("east");
}
void Background::on_button4_clicked()
{
    setScene("west");
}


void Background::clearBackground(){
    RoomA->setBrush(Qt::white);
    RoomB->setBrush(Qt::white);
    RoomC->setBrush(Qt::white);
    RoomD->setBrush(Qt::white);
    RoomE->setBrush(Qt::white);
    RoomF->setBrush(Qt::white);
    RoomG->setBrush(Qt::white);
    RoomH->setBrush(Qt::white);
    RoomI->setBrush(Qt::white);
    RoomJ->setBrush(Qt::white);

    if(delB1)
    {
        button1->deleteLater();
        delB1=0;
    }
    if(delB2)
    {
        button2->deleteLater();
        delB2=0;
    }
    if(delB3)
    {
       button3->deleteLater();
        delB3=0;
    }
    if(delB4)
    {
        button4->deleteLater();
        delB4=0;
    }
    if(dell1)
    {
        label1->deleteLater();
        dell1=0;
    }
    if(dell2)
    {
        label2->deleteLater();
        dell2=0;
    }
    if(dell3)
    {
        label3->deleteLater();
        dell3=0;
    }
    if(dell4)
    {
        label4->deleteLater();
        dell4=0;
    }
    if(dell5)
    {
        label5->deleteLater();
        dell5=0;
    }
    if(dell6)
    {
        label6->deleteLater();
        dell6=0;
    }
    if(dell7)
    {
        label7->deleteLater();
        dell7=0;
    }
    if(zork1->currentRoom->ghostInRoom()){
        this->removeItem(zork1->vghost);
    }
    else if(zork1->currentRoom->vampireInRoom()){
        this->removeItem(zork1->vvampire);
    }
    else if(zork1->currentRoom->zombieInRoom()){
        this->removeItem(zork1->vzombie);
    }
    else if(zork1->currentRoom->mummyInRoom()){
        this->removeItem(zork1->vmummy);
    }
    else if(zork1->currentRoom->dragonInRoom()){
        this->removeItem(zork1->vdragon);
    }
    else if(zork1->currentRoom->alienInRoom()){
        this->removeItem(zork1->valien);
    }
    else if(zork1->currentRoom->pirateInRoom()){
        this->removeItem(zork1->vpirate);
    }
    this->removeItem(cave);

    zork1->vghost->resetHealth();
    zork1->vvampire->resetHealth();
    zork1->vzombie->resetHealth();
    zork1->vmummy->resetHealth();
    zork1->vdragon->resetHealth();
    zork1->valien->resetHealth();
    zork1->vpirate->resetHealth();
    if(zork1->currentRoom->ghostInRoom()){
        timer->stopTimer();
        timer->deleteLater();
    }
    else if(zork1->currentRoom->vampireInRoom()){
        timer->stopTimer();
        timer->deleteLater();
    }
    else if(zork1->currentRoom->zombieInRoom()){
        timer->stopTimer();
        timer->deleteLater();
    }
    else if(zork1->currentRoom->mummyInRoom()){
        timer->stopTimer();
        timer->deleteLater();
    }
    else if(zork1->currentRoom->dragonInRoom()){
        timer->stopTimer();
        timer->deleteLater();
    }
    else if(zork1->currentRoom->alienInRoom()){
        timer->stopTimer();
        timer->deleteLater();
    }
    else if(zork1->currentRoom->pirateInRoom()){
        timer->stopTimer();
        timer->deleteLater();
    }
}

void Background::keyPressEvent(QKeyEvent *event)
{
    if(zork1->currentRoom->ghostInRoom()){
        if(event->key()==Qt::Key_X)
        {
                if(zork1->vghost->scenePos()==QPointF(470,200)){
                    zork1->vghost->decreaseHealthByAttack(10);
                    zork1->vghost->setPixmap(QPixmap(":/Images/ghostattack.png"));
                    zork1->vghost->z=1;
                    if(zork1->vghost->getHealth()<=0){
                        zork1->currentRoom->setghost(false);
                        label1 = new QLabel();
                        label1->setText("T");
                        QFont font = label1->font();
                        font.setPointSize(72);
                        label1->setFont(font);
                        label1->move(450,100);
                        dell1=1;
                        this->addWidget(label1);
                        zork1->d->setCanEnter(true);
                    }
                }
        }
    }
    else if(zork1->currentRoom->vampireInRoom()){
        if(event->key()==Qt::Key_X)
        {
                if(zork1->vvampire->scenePos()==QPointF(470,200)){
                    zork1->vvampire->decreaseHealthByAttack(10);
                    zork1->vvampire->setPixmap(QPixmap(":/Images/vampireattack.jpg"));
                    zork1->vvampire->z=1;
                    if(zork1->vvampire->getHealth()<=0){
                        zork1->currentRoom->setvampire(false);
                        label2 = new QLabel();
                        label2->setText("N");
                        QFont font = label2->font();
                        font.setPointSize(72);
                        label2->setFont(font);
                        label2->move(450,100);
                        dell2=1;
                        this->addWidget(label2);
                        zork1->e->setCanEnter(true);
                    }
                }
        }
    }
    else if(zork1->currentRoom->zombieInRoom()){
        if(event->key()==Qt::Key_X)
        {
                if(zork1->vzombie->scenePos()==QPointF(470,200)){
                    zork1->vzombie->decreaseHealthByAttack(10);
                    zork1->vzombie->setPixmap(QPixmap(":/Images/zombieattack.jpg"));
                    zork1->vzombie->z=1;
                    if(zork1->vzombie->getHealth()<=0){
                        zork1->currentRoom->setzombie(false);
                        label3 = new QLabel();
                        label3->setText("I");
                        QFont font = label3->font();
                        font.setPointSize(72);
                        label3->setFont(font);
                        label3->move(450,100);
                        dell3=1;
                        this->addWidget(label3);
                        zork1->b->setCanEnter(true);
                    }
                }
        }
    }
    else if(zork1->currentRoom->mummyInRoom()){
        if(event->key()==Qt::Key_X)
        {
                if(zork1->vmummy->scenePos()==QPointF(470,200)){
                    zork1->vmummy->decreaseHealthByAttack(10);
                    zork1->vmummy->setPixmap(QPixmap(":/Images/mummyattack.png"));
                    zork1->vmummy->z=1;
                    if(zork1->vmummy->getHealth()<=0){
                        zork1->currentRoom->setmummy(false);
                        label4 = new QLabel();
                        label4->setText("S");
                        QFont font = label4->font();
                        font.setPointSize(72);
                        label4->setFont(font);
                        label4->move(450,100);
                        dell4=1;
                        this->addWidget(label4);
                        zork1->g->setCanEnter(true);
                    }
                }
        }
    }
    else if(zork1->currentRoom->dragonInRoom()){
        if(event->key()==Qt::Key_X)
        {
                if(zork1->vdragon->scenePos()==QPointF(470,200)){
                    zork1->vdragon->decreaseHealthByAttack(10);
                    zork1->vdragon->setPixmap(QPixmap(":/Images/dragonattack.jpg"));
                    zork1->vdragon->z=1;
                    if(zork1->vdragon->getHealth()<=0){
                        zork1->currentRoom->setdragon(false);
                        label5 = new QLabel();
                        label5->setText("E");
                        QFont font = label5->font();
                        font.setPointSize(72);
                        label5->setFont(font);
                        label5->move(450,100);
                        dell5=1;
                        this->addWidget(label5);
                        zork1->f->setCanEnter(true);
                    }
                }
        }
    }
    else if(zork1->currentRoom->alienInRoom()){
        if(event->key()==Qt::Key_X)
        {
                if(zork1->valien->scenePos()==QPointF(470,200)){
                    zork1->valien->decreaseHealthByAttack(10);
                    zork1->valien->setPixmap(QPixmap(":/Images/alienattack.png"));
                    zork1->valien->z=1;
                    if(zork1->valien->getHealth()<=0){
                        zork1->currentRoom->setalien(false);
                        label6 = new QLabel();
                        label6->setText("N");
                        QFont font = label6->font();
                        font.setPointSize(72);
                        label6->setFont(font);
                        label6->move(450,100);
                        dell6=1;
                        this->addWidget(label6);
                        zork1->h->setCanEnter(true);
                    }
                }
        }
    }
    else if(zork1->currentRoom->pirateInRoom()){
        if(event->key()==Qt::Key_X)
        {
                if(zork1->vpirate->scenePos()==QPointF(470,200)){
                    zork1->vpirate->decreaseHealthByAttack(10);
                    zork1->vpirate->setPixmap(QPixmap(":/Images/pirateattack.png"));
                    zork1->vpirate->z=1;
                    if(zork1->vpirate->getHealth()<=0){
                        zork1->currentRoom->setpirate(false);
                        label7 = new QLabel();
                        label7->setText("E");
                        QFont font = label7->font();
                        font.setPointSize(72);
                        label7->setFont(font);
                        label7->move(450,100);
                        dell7=1;
                        this->addWidget(label7);
                        zork1->c->setCanEnter(true);
                    }
                }
        }
    }
}

void Background::close()
{
    delete this;
    delete zork1;
    exit(1);
}




