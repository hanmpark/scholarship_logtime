# scholarship_logtime

Hi there !  
I made a program that calculates the total logtime from the 27th to the 26th of the chosen month to the nearest second with and without the bonus logtime if there's any.  
You have to do 140 hours between those dates to complete the attendance requirements of the GEN scholarship.
Therefore, the bonus logtime is the extra hours you did !  
**Note that you can only cumulate up to _70 hours_ of bonus logtime and it's only applicable for the next month !**

## Installation

Git clone my repo !

```bash
  git clone https://github.com/Nonino42/scholarship_logtime.git
```

Go to the project directory

```bash
  cd scholarship_logtime
```
## Configuration

### Ruby

To run this project, you will have to install Ruby if it's not installed yet. Note that on mac it is already pre-installed. To check it, do:

```bash
  which ruby
```

You should get something like

```bash
  /usr/bin/ruby
```

Once you have it, run the following command line in scholarship_logtime/ to create your **Gemfile**:

```bash
  bundle init
```

Now we need the **Gemfile.lock** to add dependencies we need in our program.

```bash
  bundle add oauth2
```

```bash
  bundle add scanf
```

### API

To access the 42 API, you will have to create an application v2.

Go to your intra, click on your profile, settings, API, register a new app.

- **Name** = _scholarship_logtime_

- **Redirect URI** = _https://profile.intra.42.fr/_

The others you can skip.

Now, add the following environment variables:

```bash
  UID_42="UID_of_your_application"
  SECRET_42="SECRET_of_your_application"
```
## You are finally good to go !

Now execute the shell script by using the following command line:

```bash
  ./sslog your_42_login
```

## Documentation

[Documentation](https://api.intra.42.fr/apidoc/guides/getting_started)


## Authors

- [@Nonino42](https://www.github.com/Nonino42)
