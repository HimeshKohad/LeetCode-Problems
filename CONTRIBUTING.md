# Contributing Guidelines for Leetcode-Problems

Welcome to the Leetcode-Problems repository! We appreciate your interest in contributing to this project. By following these guidelines, you can help us maintain a high-quality collection of Leetcode solutions. Please take a moment to review this document before making any contributions.

## Table of Contents

- [Getting Started](#getting-started)
  - [Forking the Repository](#forking-the-repository)
  - [Cloning the Repository](#cloning-the-repository)
- [Contributing](#contributing)
  - [Creating a Branch](#creating-a-branch)
  - [Implementing Solutions](#implementing-solutions)
  - [Code Style](#code-style)
  - [Testing](#testing)
  - [Committing Changes](#committing-changes)
  - [Pushing Changes](#pushing-changes)
  - [Opening a Pull Request](#opening-a-pull-request)
- [Review Process](#review-process)
- [Code of Conduct](#code-of-conduct)
- [License](#license)

## Getting Started

To contribute to the Leetcode-Problems repository, you'll need to follow these initial steps.

### Forking the Repository

1. Navigate to the [Leetcode-Problems repository](https://github.com/HimeshKohad/LeetCode-Problems).
2. Click on the **Fork** button located at the top right corner of the page.
3. Wait for the repository to be forked into your GitHub account.

### Cloning the Repository

1. On your forked repository, click on the **Code** button.
2. Copy the repository URL.
3. Open your terminal or Git client.
4. Navigate to the directory where you want to clone the repository.
5. Run the following command:

   ```shell
   git clone <repository-url>
   ```

   Replace `<repository-url>` with the URL you copied.

Now you have the repository cloned and ready for making contributions.

## Contributing

Follow these guidelines to contribute to the Leetcode-Problems repository.

### Creating a Branch

1. Before making any changes, create a new branch with a descriptive name.
2. Use the following command to create a branch:

   ```shell
   git checkout -b branch-name
   ```

   Replace `branch-name` with a short, meaningful branch name that describes your contribution.

### Implementing Solutions

1. Inside the repository, navigate to the relevant problem category or create a new one if necessary.
2. Create a new directory with the problem name in kebab-case.
3. Add the solution file(s) inside the problem directory.
4. Include a README.md file in the problem directory, explaining the problem statement, approach, and any additional notes.
5. If there are multiple solutions, name them appropriately, e.g., `solution.md`, `cpp-solution.cpp`, etc.
6. Ensure your code is well-documented and easy to understand.

### Code Style

1. Follow the existing code style and conventions used in the repository.
2. If possible, include appropriate comments and docstrings to explain the logic and any important details.
3. Adhere to the language-specific best practices and guidelines.

### Testing

1. Before committing your changes, test your code locally to ensure it runs correctly.
2. Write test cases whenever possible to verify the correctness of your solution.
3. Run the existing test suite (if any) to check for any regressions.

### Committing Changes

1. Once you are satisfied with your implementation, commit your changes.
2. Use descriptive and concise commit messages.
3. Separate logical changes into multiple commits if necessary.

### Pushing Changes

1. After

 committing your changes, push them to your forked repository.
2. Use the following command to push your changes:

   ```shell
   git push origin branch-name
   ```

   Replace `branch-name` with the name of the branch you created earlier.

### Opening a Pull Request

1. Go to the original [Leetcode-Problems repository](https://github.com/HimeshKohad/LeetCode-Problems).
2. Click on the **Pull requests** tab.
3. Click on the **New pull request** button.
4. Select your forked repository and branch from the dropdowns.
5. Provide a descriptive title and include any additional context or information in the comment box.
6. Click on the **Create pull request** button to submit your contribution.

## Review Process

The repository maintainers will review your pull request as soon as possible. Please be patient during this process. They may provide feedback or request changes to ensure the quality and consistency of the repository. Once approved, your contribution will be merged into the main branch.

## Code of Conduct

Please review and adhere to the [Code of Conduct](CODE_OF_CONDUCT.md) when participating in this project.

## License

By contributing to the Leetcode-Problems repository, you agree that your contributions will be licensed under the [GNU License](LICENSE).
