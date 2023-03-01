![time banner](https://kiwiorthoticservices.com/wp-content/uploads/saving-time-banner.jpg)

<h1 align="center">⏱ scholarship_logtime ⏱</h1>

Hello there ! 🙌

Here's my first personal project which is a program that may be interesting to **42 GEN scholarship students**:  
It calculates the total logtime a person has done from the 27th to the 26th of the current month or the month you chose, counting _*bonus time_ from the previous month if there is any !   

## NOTES 📝
   -  If you have chosen the current month, the program also tells you:
      - how much time is left before the 27th
      - how many days are left before the 27th (counting days off if you have set any)
      - how much time you should do each day (counting days off if you have set any
   - **Note that you can only cumulate up to _70 hours_ of bonus logtime and it's only applicable for the next month**
   - **If the logs of the day are not displayed, you have to wait until midnight**
   - **You can't choose a month that is older than 4 months**
   - **During public holidays, it will append 7 hours to the total logtime automatically**
   - **If you do logtime during a public holiday, it will append to the 7 hours**
   
### ‼️ IT DOESN'T TELL THE EXACT LOGTIME ‼️
   - **The program doesn't calculate manually added logtimes**
   - **My _bonus logtime_ is not the same as the real bonus logtime**
   - **If you have a doubt about your logtime, please ask your staff**

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
## You are finally good to go ! 🤩

Execute the program by doing like so:

```bash
  ./sslog.sh your_42_login chosen_month -s
```

If you don't put anything for the chosen_month, it will automatically choose the current month  
If you put the "-s" flag it will show you the dates

## Documentation 📕

[Documentation](https://api.intra.42.fr/apidoc/guides/getting_started)


## Authors 👨‍💻

- [@Nonino42](https://www.github.com/Nonino42)

Feel free to contact me if you have anything to say about the program / bugs !
