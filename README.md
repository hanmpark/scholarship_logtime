# scholarship_logtime
Introducing ***scholarship_logtime*** an exlusively designed program for **42 Nice GEN scholarship students**: <br>
This tool is crafted to effortlessly calculate the cumulative logtime for individuals, spanning from the 27th to the 26th of the current month or any specified month. <br>

> [!NOTE]
> Notably, it even accounts for any bonus time earned in the preceding month, ensuring a comprehensive assessment of your dedicated efforts!

### Features
***scholarship_logtime*** offers you comprehensive and personalized insights
- **Time Remaining:** Discover precisely how much time remains until the 27th of the month, enabling you to plan your activities and optimize your logtime effectively.
- **Days Remaining:** Get a clear count of the days left before the 27th, thoughtfully considering any set days off, ensuring you stay on track and make the most of every opportunity.
- **Daily Target:** To help you pace your efforts intelligently, the program calculates the amount of time you should aim to complete each day, carefully accounting for any planned days off, so you can attain your scholarship goals.

> [!IMPORTANT]
> - **BONUS LOG**: Note that you can cumulate up to **70 hours** of bonus logtime and it's only applicable for the following month
> - **LOGS NOT DISPLAYED**: It refreshes at midnight
> - **PUBLIC HOLIDAYS**: Automatically add 7 hours to your logtime counter. If you come that day, the logtime you complete will be added to this initial 7-hour base

## Installation
Git clone my repo

```bash
  git clone https://github.com/Nonino42/scholarship_logtime.git
```

> [!IMPORTANT]  
> To be able to run the program, you will have to install the `jq` command

### API
As the program needs to access the 42 API, you will have to create an application v2 in your intra

For that, go on your intra, click on your profile, settings, API, register a new app at the top right on your screen

- **Name** = _scholarship_logtime_

- **Redirect URI** = _https://profile.intra.42.fr/_

You can skip the other cases

Now you should have your **_UID_** and your **_SECRET_**

Now go back to your terminal and launch the executable `init_sslog`. It will ask you to put the important information such as the UID and the SECRET of your application

## Start the program

You can use the -h (or --help) option to get information about the program
    
```bash
  ./sslog.sh -h
```

To start using it right away, you can use the -l option to specify your login and -m to specify the month

```bash
  ./sslog.sh -l your_42_login -m chosen_month -s
  
  #If you don't put anything for the chosen_month, it will automatically choose the current month
  #If you put the "-s" flag it will show you the dates
```

## Documentation
[Documentation](https://api.intra.42.fr/apidoc/guides/getting_started)

## Contributing
If you come up with any ideas/issues, feel free to contribute !
