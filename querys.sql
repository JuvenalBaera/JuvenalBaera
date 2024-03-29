CREATE DATABASE IF NOT EXISTS addressbook;

USE addressbook;

CREATE TABLE IF NOT EXISTS contacts (
    first_name VARCHAR(20) NOT NULL,
    last_name VARCHAR(20) NOT NULL,
    phone_number VARCHAR(15) NOT NULL,
    email VARCHAR(40) NOT NULL,
    PRIMARY KEY (phone_number)
);

INSERT INTO contacts 
(first_name, last_name, phone_number, email)
VALUES
("Annabal", "Faye", "155564645", "afayew@github.com"),
("Dexter", "Senussi", "197632695", "dsenussip@blogspot.com"),
("Linn", "Jeans", "554396014", "ljeansm@indiatimes.com"),
("Lorrin", "Bartkiewicz", "445001767", "lbartkiewiczn@discovery.com"),
("Ninette", "Bartali", "297211690", "nbartaliv@admin.ch"),
("Pamela", "Bolstridge", "066621073", "pbolstridge6@bandcamp.com"),
("Mady", "Prettyjohns", "654370542", "mprettyjohnsy@bloglines.com"),
("Dex", "Gallego", "326677103", "dgallego13@msn.com"),
("Serena", "Finlater", "369490053", "sfinlater1@redcross.org"),
("Finey", "Clem", "346766545", "ffineyc@prlog.org"),
("Judi", "McGaughie", "312950145", "jmcgaughiet@abc.net.au"),
("Cordy", "Hancock", "271755691", "chancockz@nps.gov"),
("De", "Vries", "665937003", "mdevriesl@columbia.edu"),
("Pickard", "Paton", "637619607", "rpickarde@sun.com"),
("Linkin", "Edik", "846752976", "mlinkina@nps.gov"),
("Latisha", "Macconachy", "133391062", "lmacconachy12@macromedia.com"),
("Shoshanna", "Trittam", "996720793", "strittamu@ed.gov"),
("Sheelagh", "Bagnal", "341953784", "sbagnal5@nifty.com"),
("Ricardo", "Tolotti", "631160307", "rtolotti11@nhs.uk"),
("Buzek", "Ragnar", "290324585", "cbuzekd@blinklist.com"),
("Steward", "Shallcroff", "338701666", "sshallcroff2@desdev.cn"),
("Charles", "Pita", "845500113", "charles@gmail.com"),
("Korneichik", "Francene", "624720065", "ekorneichikb@lycos.com"),
("Ced", "Senchenko", "051339447", "csenchenkos@blogger.com"),
("Meredith", "Gostick", "370328026", "mgostick4@army.mil"),
("Lion", "Brightey", "833877938", "lbrightey1@example.com"),
("Mac", "Coils", "338600662", "mcoils6@newyorker.com"),
("Teador", "Polini", "868603800", "tpolini0@dot.gov"),
("Hazel", "Fodden", "997586689", "hfodden8@dagondesign.com"),
("Skittle", "Zahara", "371119912", "bskittleg@cnet.com"),
("Jonie", "Lammerding", "962921692", "jlammerdingr@reddit.com"),
("Graith", "Bartel", "550500855", "zgraithh@ucla.edu"),
("Breckon", "Carlina", "316842586", "bbreckoni@illinois.edu"),
("Gigi", "Randalston", "951927029", "grandalston4@cloudflare.com"),
("Glasgow", "Zacharia", "837298765", "cglasgowj@seattletimes.com"),
("Rudolph", "Carp", "718175107", "rcarp3@wikipedia.org"),
("Joyann", "Pozzo", "552217973", "jpozzo0@nymag.com"),
("Skitral", "Mario", "570886840", "zskitralk@alexa.com"),
("Una", "Cuerdale", "152643784", "ucuerdale5@booking.com"),
("Amory", "Piddock", "325497215", "apiddocko@engadget.com"),
("Dru", "Yve", "752182229", "dyve7@admin.ch"),
("Juvenal", "Baera", "925447968", "jbaera@gmail.com"),
("Lynne", "Grevile", "251987043", "lgrevile3@google.de"),
("Paola", "Edeler", "275501091", "pedeler2@squidoo.com"),
("Cairistiona", "Pilmer", "501276850", "cpilmer7@cbc.ca"),
("Scott", "Kirley", "279680623", "skirley8@hubpages.com"),
("Tom", "Matyushenko", "860997985", "tmatyushenko10@ucla.edu"),
("Terron", "Burke", "804603174", "pterronf@nyu.edu"),
("Ambrosi", "Rumford", "230534629", "arumfordq@reuters.com"),
("Alexandros", "Sapson", "918909550", "asapsonx@cnet.com"),
("Longmead", "Marget", "474843416", "alongmead9@webmd.com");

SELECT * FROM contacts;
