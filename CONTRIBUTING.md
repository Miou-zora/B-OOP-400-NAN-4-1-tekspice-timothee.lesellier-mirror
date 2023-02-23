# Contributing

When contributing to this repository, please first discuss the change you wish to make via issue,
email, or any other method with the owners of this repository before making a change. 
Please note we have a code of conduct, please follow it in all your interactions with the project.

(When interacting with us, please be human being)


## Test Policies

### Framework
`criterion`

### Coverage
#### PR : -> main 
We want 80% coverage (if not for technical reason like testing a malloc or getline you'll have to explain why it's not possible)
### PR : -> other branch
We want 60% coverage (if not, look above)

## Memory Management
If you want to check memory leaks, you can use `valgrind --track-fds=yes --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt  --leak-check=full -s ./nanotekspice tests/BuilderTestsFolder/test7` command.

## Commit
Please use [Angular](https://www.conventionalcommits.org/en/v1.0.0-beta.4/).


## Pull Request Process

### Code review
For each PR we'll have a code review, the PR must be approved by the developpers team.

### PR Stability
Look at the **Testing Policies**

## Coding style
It's free, but please don't be a dick and think a bit when writting code.

