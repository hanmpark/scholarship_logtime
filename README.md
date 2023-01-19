![time banner](https://kiwiorthoticservices.com/wp-content/uploads/saving-time-banner.jpg)

<h1 align="center"> scholarship_logtime</h1>

Hello there !

Here's my first personal project which is a program that may be interesting to **GEN scholarship students**:  
It calculates the total logtime a person has done from the 27th to the 26th of the current month or the month you chose, counting bonus time from the previous month if there is any !  
It tells you the public holidays of the month and adds 7 hours automatically.  
If you have chose the current month, the program also tells you:
- how much time is left before the 27th
- how many days are left before the 27th (counting days off if you have set any)
- how much time you should do each day (counting days off if you have set any)

NOTES:
- **Note that you can only cumulate up to _70 hours_ of bonus logtime and it's only applicable for the next month**
- **If the logs of the day are not displayed, you have to wait until midnight**
- **The program doesn’t calculate manually added logtimes**
- **You can't choose a month that is older than 4 months**
- **If you do logtime during a public holiday, it will append 7 hours to the logtime**

## Prerequisite

First of all, to run this project, you will have to install Ruby if it's not installed yet. Note that on mac it is already pre-installed. To check it, do:

```bash
  which ruby
```

You should get something like

```bash
  /usr/bin/ruby
```

Else, follow [this link](https://www.ruby-lang.org/en/documentation/installation/)

**Note that at school, you don't have permission to change versions, or add and install gems so please follow the next command lines to install rbenv:**

```bash
  curl -fsSL https://github.com/rbenv/rbenv-installer/raw/HEAD/bin/rbenv-installer | bash
```

Once you have installed rbenv, it should tell you how to configure your shell to load rbenv and the command should look **_something like this_**:
```bash
  echo 'eval "$(~/.rbenv/bin/rbenv init - zsh)"' >> ~/.zshrc
```
Or if you don't find the command please follow this [link](https://github.com/rbenv/rbenv)

Then restart your terminal or simply _exec zsh_ and do
```bash
  rbenv install 2.6.10
  rbenv global 2.6.10
```

_exec zsh_ again and now when you do _ruby -v_ you should get the version you just installed.

## Installation

Only then you can git clone my repo  
If you have cloned it already reclone it

```bash
  git clone https://github.com/Nonino42/scholarship_logtime.git
```

Go to the project directory

```bash
  cd scholarship_logtime
```

Once you have it, run the following command line in scholarship_logtime/ to create your **Gemfile**:

```bash
  bundle init
```

Now we need the **Gemfile.lock** to add dependencies we need in our program.

```bash
  bundle add oauth2
  bundle add scanf
  bundle install
```

### API

As the program needs to access the 42 API, you will have to create an application v2 in your intra.

For that, go on your intra, click on your profile, settings, API, register a new app at the top right on your screen.

- **Name** = _scholarship_logtime_

- **Redirect URI** = _https://profile.intra.42.fr/_

The others you can skip.

Now you should have your **_UID_** and your **_SECRET_**

Now go back to your terminal and add the following environment variables with the _export_ command:

```bash
  export UID_42="UID_of_your_application"
  export SECRET_42="SECRET_of_your_application"
```
## You are finally good to go !

Don't forget to compile first:

```bash
  make all
```

Now execute the program by using the simple command line:

```bash
  ./sslog.sh your_42_login chosen_month
```

If you don't put anything for the chosen_month, it will automatically choose the current month.

## Documentation

[Documentation](https://api.intra.42.fr/apidoc/guides/getting_started)


## Authors

- [@Nonino42](https://www.github.com/Nonino42)

Feel free to contact me if you have anything to say about the program / bugs !
