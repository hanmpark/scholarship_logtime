![time banner](https://kiwiorthoticservices.com/wp-content/uploads/saving-time-banner.jpg)

<h1 align="center">⏱ scholarship_logtime ⏱</h1>

<h4 align="center"><a href="https://github.com/Nonino42/scholarship_logtime/edit/main/README.md#installation-">[Installation]</a> • <a href="https://github.com/Nonino42/scholarship_logtime/edit/main/README.md#you-are-good-to-go--">[Start]</a> • <a href="https://github.com/Nonino42/scholarship_logtime/edit/main/README.md#notes-">[Notes]</a></h4>

Hello there ! 🙌

Here's my first personal project which is a program that may be interesting to **42 GEN scholarship students**:  
It calculates the total logtime a person has done from the 27th to the 26th of the current month or the month you chose, counting **bonus time** from the previous month if there is any !   

<a name="installation"/>

## Installation 💾

Git clone my repo

```bash
  git clone https://github.com/Nonino42/scholarship_logtime.git
```

### API 📡

As the program needs to access the 42 API, you will have to create an application v2 in your intra

For that, go on your intra, click on your profile, settings, API, register a new app at the top right on your screen

- **Name** = _scholarship_logtime_

- **Redirect URI** = _https://profile.intra.42.fr/_

You can skip the other cases

Now you should have your **_UID_** and your **_SECRET_**

Now go back to your terminal and set your application's UID and SECRET in _sslog.sh_ file

```bash
  UID_42="your_application_UID"
  SECRET_42="your_application_SECRET"
```

<a name="start"/>

## You are good to go ! 🤩

Execute the program by doing like so:

```bash
  ./sslog.sh your_42_login chosen_month -s
  
  #If you don't put anything for the chosen_month, it will automatically choose the current month
  #If you put the "-s" flag it will show you the dates
```

<a name="notes"/>

## NOTES 📝
   -  If you have chosen the current month, the program also tells you:
      - how much time is left before the 27th
      - how many days are left before the 27th (counting days off if you have set any)
      - how much time you should do each day (counting days off if you have set any)

| FAQ | ANSWER |
| :-: | --- |
| BONUS LOG | Note that you can cumulate up to **70 hours** of bonus logtime and it's only applicable for the next month |
| LOGS NOT DISPLAYED YET | you have to wait until midnight ! |
| CAN WE CHOOSE ANY MONTH | You can't choose a month that is older than 4 months |
| PUBLIC HOLIDAYS | Automatically add 7 hours; if you come that day, the logtime you will do will be appended to it |

<h3 align="center">‼️ IT DOESN'T TELL THE EXACT LOGTIME ‼️</h3>

<div align="center">
   <p><strong>My _bonus logtime_ is not the same as the real bonus logtime</strong></p>
   <p><strong>If you have a doubt about your logtime, please ask your staff</strong></p>
</div>

<a name="documentation"/>

## Documentation 📕

[Documentation](https://api.intra.42.fr/apidoc/guides/getting_started)


## Author 👨‍💻

- [@Nonino42](https://www.github.com/Nonino42)

Feel free to contact me if you have anything to say about the program / bugs !
