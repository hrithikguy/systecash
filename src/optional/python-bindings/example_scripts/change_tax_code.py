#!/usr/bin/env python

##  @file
#   @brief Output all the credits and debits on an account
#   @ingroup python_bindings_examples

from systecash import Session, Account

# choose the account code to select
TARGET_ACCOUNT_CODE = '1234'

def mark_account_with_code_as_tax_related(account, target_code):
    """Looks at account to see if it has the target_account_code, if so
    set the account tax related flag to True and return True.
    If not, recursively tries to do the same to all children accounts
    of account.
    Returns False when recursion fails to find it.
    """
    if account.GetCode() == target_code:
        account.SetTaxRelated(True)
        return True
    else:
        for child in account.get_children():
            if mark_account_with_code_as_tax_related(child, target_code):
                return True
        return False
            
# Change this path to your own
systecash_session = Session("/home/mark/python-bindings-help/test.xac")

mark_account_with_code_as_tax_related(
    systecash_session.book.get_root_account(),
    TARGET_ACCOUNT_CODE)

systecash_session.save()
systecash_session.end()
