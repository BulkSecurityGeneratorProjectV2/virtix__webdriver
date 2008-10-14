package org.openqa.selenium.internal;

import org.openqa.selenium.WebElement;

public class ValueOptionSelectStrategy extends BaseOptionSelectStrategy {
    protected boolean selectOption(WebElement option, String selectThis) {
        return selectThis.equals(option.getValue());
    }
}
